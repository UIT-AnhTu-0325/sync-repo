package routes

import (
	"example/webservice-gin/controllers"

	"github.com/gin-gonic/gin"
)

func GetRoute() *gin.Engine {
	router := gin.Default()

	//Demo API with mongoDB
	router.GET("/albums", controllers.GetAlbums)
	router.GET("/albums/:id", controllers.GetAlbumById)
	router.POST("/albums", controllers.PostAlbums)

	//Cookie-based authentication
	router.POST("/signin", controllers.Signin)
	router.GET("/welcome", controllers.Welcome)

	return router
}
