package controller

import (
	"context"
	"fmt"
	"log"
	"net/http"

	"github.com/gin-gonic/gin"
	"go.mongodb.org/mongo-driver/bson"
	"go.mongodb.org/mongo-driver/bson/primitive"
	"go.mongodb.org/mongo-driver/mongo/options"

	"example/webservice-gin/database"
	"example/webservice-gin/model"
)

func GetAlbums(c *gin.Context) {
	client := database.GetMongo()
	defer func() {
		if err := client.Disconnect(context.TODO()); err != nil {
			log.Fatal(err)
		}
		fmt.Println("Closed MongoDB!")
	}()
	collection := client.Database("test").Collection("albums")
	findOptions := options.Find()
	findOptions.SetLimit(3)

	var results []*model.Album
	cur, err := collection.Find(context.TODO(), bson.D{{}}, findOptions)
	if err != nil {
		log.Fatal(err)
	}
	for cur.Next(context.TODO()) {
		var elem model.Album
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
	client := database.GetMongo()
	defer func() {
		if err := client.Disconnect(context.TODO()); err != nil {
			log.Fatal(err)
		}
		fmt.Println("Closed MongoDB!")
	}()
	collection := client.Database("test").Collection("albums")

	var newAlbum model.Album

	if err := c.BindJSON(&newAlbum); err != nil {
		return
	}

	result, errIns := collection.InsertOne(context.TODO(), newAlbum)

	if errIns != nil {
		log.Fatal(errIns)
	}

	c.IndentedJSON(http.StatusCreated, result)
}

func GetAlbumById(c *gin.Context) {
	client := database.GetMongo()
	defer func() {
		if err := client.Disconnect(context.TODO()); err != nil {
			log.Fatal(err)
		}
		fmt.Println("Closed MongoDB!")
	}()
	collection := client.Database("test").Collection("albums")

	var result model.Album
	filter := bson.D{primitive.E{Key: "id", Value: c.Param("id")}}
	err := collection.FindOne(context.TODO(), filter).Decode(&result)
	if err != nil {
		c.IndentedJSON(http.StatusNotFound, gin.H{"message": err.Error()})
		return
	}
	c.IndentedJSON(http.StatusOK, result)
}
