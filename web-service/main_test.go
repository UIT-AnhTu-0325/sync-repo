package main

import (
	"encoding/json"
	"io/ioutil"
	"net/http"
	"net/http/httptest"
	"testing"

	"github.com/gin-gonic/gin"
	"github.com/go-playground/assert/v2"
)

func SetUpRouter() *gin.Engine {
	router := gin.Default()
	return router
}

func TestGetAlbums(t *testing.T) {
	r := SetUpRouter()
	r.GET("/albums", GetAlbums)
	req, _ := http.NewRequest("GET", "/albums", nil)
	w := httptest.NewRecorder()
	r.ServeHTTP(w, req)

	res, _ := ioutil.ReadAll(w.Body)
	var arr []string
	_ = json.Unmarshal([]byte(res), &arr)

	assert.Equal(t, len(arr), 3)
	assert.Equal(t, http.StatusOK, w.Code)
}

// func FuzzGetAlbumById(f *testing.F) {
// 	r := SetUpRouter()
// 	r.GET("/albums/:id", GetAlbumById)

// 	testcases := []int{1, 2, 3}
// 	for _, tc := range testcases {
// 		f.Add(tc)
// 	}
// 	f.Fuzz(func(t *testing.T, a int) {
// 		req, _ := http.NewRequest("GET", "/albums/"+strconv.Itoa(a), nil)
// 		w := httptest.NewRecorder()
// 		r.ServeHTTP(w, req)
// 		res, _ := ioutil.ReadAll(w.Body)
// 		var data album
// 		_ = json.Unmarshal([]byte(res), &data)
// 		assert.Equal(t, data.ID, strconv.Itoa(a))
// 		assert.Equal(t, http.StatusOK, w.Code)
// 	})
// }
