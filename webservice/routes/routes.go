package routes

import (
	"example/webservice-gin/controllers"
	"net/http"

	"github.com/gin-gonic/gin"
)

func GetRoute() *gin.Engine {
	router := gin.Default()

	//Test func
	router.GET("/api/webservice", func(c *gin.Context) {
		c.JSON(http.StatusOK, gin.H{
			"hello": "kindly folks 90",
		})
	})

	//Demo API with mongoDB
	router.GET("/api/webservice/albums", controllers.GetAlbums)
	router.GET("/api/webservice/albums/:id", controllers.GetAlbumById)
	router.POST("/api/webservice/albums", controllers.PostAlbums)

	//Cookie-based authentication
	router.POST("/api/webservice/signin", controllers.Signin)
	router.GET("/api/webservice/welcome", controllers.Welcome)

	return router
}
