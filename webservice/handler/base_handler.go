package handler

import (
	"example/webservice-gin/model"
	"net/http"
	"os"

	"github.com/gin-gonic/gin"
)

type Handler struct {
	UserService  model.UserService
	TokenService model.TokenService
}

type Config struct {
	R            *gin.Engine
	UserService  model.UserService
	TokenService model.TokenService
}

func NewHandler(c *Config) {
	g := c.R.Group(os.Getenv("WEB_SERVICE_API_URL"))
	h := &Handler{
		UserService:  c.UserService,
		TokenService: c.TokenService,
	}
	//Test func
	g.GET("/", func(ctx *gin.Context) {
		ctx.JSON(http.StatusOK, gin.H{
			"Hello": "It's my world!",
		})
	})

	g.GET("/me", h.Me)
	g.POST("/signup", h.Signup)
}
