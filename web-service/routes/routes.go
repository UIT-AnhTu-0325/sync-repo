package routes

import (
	"example/web-service-gin/controllers"

	"github.com/gin-gonic/gin"
)

func GetRoute() *gin.Engine {
	router := gin.New()

	router.GET("/albums", controllers.GetAlbums)
	router.GET("/albums/:id", controllers.GetAlbumById)
	router.POST("/albums", controllers.PostAlbums)

	return router
}
