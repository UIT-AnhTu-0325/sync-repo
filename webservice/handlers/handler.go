package handlers

import (
	"example/webservice-gin/controllers"
	"net/http"

	"github.com/gin-gonic/gin"
)

type Config struct {
	R *gin.Engine
}

func NewHandler(c *Config) {
	g := c.R.Group("/api/webservice")
	//Test func
	g.GET("/", func(c *gin.Context) {
		c.JSON(http.StatusOK, gin.H{
			"Hello": "It's my world!",
		})
	})
	//Demo API with mongoDB
	g.GET("/albums", controllers.GetAlbums)
	g.GET("/albums/:id", controllers.GetAlbumById)
	g.POST("/albums", controllers.PostAlbums)

	//Cookie-based authentication
	g.POST("/signin", controllers.Signin)
	g.GET("/welcome", controllers.Welcome)
}
