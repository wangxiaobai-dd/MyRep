package main

import (
	"fmt"
	"log"
	"net/http"
)

func queryLog(w http.ResponseWriter, r *http.Request) {
	r.ParseForm()
	fmt.Println("server:", r.Form["server"])
}

func main() {
	http.HandleFunc("/query", queryLog)
	err := http.ListenAndServe(":8001", nil)
	if err != nil {
		log.Fatal("ListenAndServe:", err)
	}
}
