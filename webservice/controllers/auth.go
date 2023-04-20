package controllers

import (
	"example/webservice-gin/models"
	"fmt"
	"net/http"
	"time"

	"github.com/gin-gonic/gin"
	"github.com/golang-jwt/jwt/v5"
)

var users = map[string]string{
	"user1": "password1",
	"user2": "password2",
}
var jwtKey = []byte("my_secret_key")

type Claims struct {
	Username string `json:"username"`
	jwt.RegisteredClaims
}

func Signin(c *gin.Context) {
	var user models.User
	if err := c.BindJSON(&user); err != nil {
		c.IndentedJSON(http.StatusBadRequest, gin.H{"error": err.Error()})
		return
	}

	expectedPassword, ok := users[user.Email]
	if !ok || expectedPassword != user.Password {
		c.IndentedJSON(http.StatusUnauthorized, gin.H{})
		return
	}

	expirationTime := time.Now().Add(5 * time.Minute)
	claims := &Claims{
		Username: user.Email,
		RegisteredClaims: jwt.RegisteredClaims{
			ExpiresAt: jwt.NewNumericDate((expirationTime)),
		},
	}
	token := jwt.NewWithClaims(jwt.SigningMethodHS256, claims)
	tokenString, err := token.SignedString(jwtKey)
	if err != nil {
		c.IndentedJSON(http.StatusInternalServerError, gin.H{"error": err.Error()})
		return
	}
	c.SetCookie("token", tokenString, 3600*1000, "/", "localhost", false, true)
}

func Welcome(c *gin.Context) {
	cookie, err := c.Cookie("token")
	if err != nil {
		if err == http.ErrNoCookie {
			c.IndentedJSON(http.StatusUnauthorized, gin.H{"error": err.Error()})
			return
		}
		c.IndentedJSON(http.StatusBadRequest, gin.H{"error": err.Error()})
		return
	}

	claims := &Claims{}

	tkn, err := jwt.ParseWithClaims(cookie, claims, func(token *jwt.Token) (interface{}, error) {
		return jwtKey, nil
	})
	if err != nil {
		if err == jwt.ErrSignatureInvalid {
			c.IndentedJSON(http.StatusUnauthorized, gin.H{"error": err.Error()})
			return
		}
		c.IndentedJSON(http.StatusBadRequest, gin.H{"error": err.Error()})
		return
	}
	if !tkn.Valid {
		c.IndentedJSON(http.StatusUnauthorized, gin.H{"error": "!tkn.Valid"})
		return
	}
	c.IndentedJSON(http.StatusOK, gin.H{"message": fmt.Sprintf("Welcome %s!", claims.Username)})
}
