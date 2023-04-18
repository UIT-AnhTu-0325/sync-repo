package main

import (
	"context"
	"fmt"
	"log"
	"net/http"

	"github.com/gin-gonic/gin"
	"go.mongodb.org/mongo-driver/bson"
	"go.mongodb.org/mongo-driver/mongo"
	"go.mongodb.org/mongo-driver/mongo/options"
)

type album struct {
	ID     string  `json:"id"`
	Title  string  `json:"title"`
	Artist string  `json:"artist"`
	Price  float64 `json:"price"`
}

func GetMongo() *mongo.Client {
	serverAPI := options.ServerAPI(options.ServerAPIVersion1)
	opts := options.Client().ApplyURI("").SetServerAPIOptions(serverAPI)
	client, err := mongo.Connect(context.TODO(), opts)
	if err != nil {
		log.Fatal(err)
	}
	err = client.Ping(context.TODO(), nil)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println("Pinged your deployment. You successfully connected to MongoDB!")

	return client
}

func GetAlbums(c *gin.Context) {
	client := GetMongo()
	defer func() {
		if err := client.Disconnect(context.TODO()); err != nil {
			log.Fatal(err)
		}
		fmt.Println("Closed MongoDB!")
	}()
	collection := client.Database("test").Collection("albums")
	findOptions := options.Find()
	findOptions.SetLimit(3)

	var results []*album
	cur, err := collection.Find(context.TODO(), bson.D{{}}, findOptions)
	if err != nil {
		log.Fatal(err)
	}
	for cur.Next(context.TODO()) {
		var elem album
		err := cur.Decode(&elem)
		if err != nil {
			log.Fatal(err)
		}
		results = append(results, &elem)
	}
	if err := cur.Err(); err != nil {
		log.Fatal(err)
	}
	cur.Close(context.TODO())
	c.IndentedJSON(http.StatusOK, results)
}

func PostAlbums(c *gin.Context) {
	client := GetMongo()
	defer func() {
		if err := client.Disconnect(context.TODO()); err != nil {
			log.Fatal(err)
		}
		fmt.Println("Closed MongoDB!")
	}()
	collection := client.Database("test").Collection("albums")

	var newAlbum album

	if err := c.BindJSON(&newAlbum); err != nil {
		return
	}

	result, errIns := collection.InsertOne(context.TODO(), newAlbum)

	if errIns != nil {
		log.Fatal(errIns)
	}

	c.IndentedJSON(http.StatusCreated, result)
}

// func GetAlbumById(c *gin.Context) {
// 	id := c.Param("id")
// 	for _, a := range albums {
// 		if a.ID == id {
// 			c.IndentedJSON(http.StatusOK, a)
// 			return
// 		}
// 	}
// 	c.IndentedJSON(http.StatusNotFound, gin.H{"message": "album not found"})
// }

func main() {

	router := gin.Default()
	router.GET("/albums", GetAlbums)
	// router.GET("/albums/:id", GetAlbumById)
	router.POST("/albums", PostAlbums)

	router.Run("localhost:8080")
}
