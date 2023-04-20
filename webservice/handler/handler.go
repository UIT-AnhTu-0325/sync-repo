package handler

import (
	"example/webservice-gin/controllers"
	"example/webservice-gin/models"
	"net/http"
	"os"

	"github.com/gin-gonic/gin"
)

type Handler struct {
	UserService models.UserService
}

type Config struct {
	R           *gin.Engine
	UserService models.UserService
}

func NewHandler(c *Config) {
	g := c.R.Group(os.Getenv("WEB_SERVICE_API_URL"))
	h := &Handler{
		UserService: c.UserService,
	}
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

	//Handler with DI
	g.GET("/me", h.Me)
}
