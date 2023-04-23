package handler

import (
	"example/webservice-gin/controller"
	"example/webservice-gin/model"
	"net/http"
	"os"

	"github.com/gin-gonic/gin"
)

type Handler struct {
	UserService model.UserService
}

type Config struct {
	R           *gin.Engine
	UserService model.UserService
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
	g.GET("/albums", controller.GetAlbums)
	g.GET("/albums/:id", controller.GetAlbumById)
	g.POST("/albums", controller.PostAlbums)

	//Cookie-based authentication
	g.POST("/signin", controller.Signin)
	g.GET("/welcome", controller.Welcome)

	//Handler with DI
	g.GET("/me", h.Me)
	g.POST("/signup", h.Signup)
}
