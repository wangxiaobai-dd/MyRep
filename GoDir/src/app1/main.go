package main

import (
	//	"fmt"
	"html/template"
	"log"
	"net/http"
)

func showPage(w http.ResponseWriter, r *http.Request) {
	t, _ := template.ParseFiles("main.html")
	t.Execute(w, nil)
}

func main() {
	http.HandleFunc("/", showPage)
	err := http.ListenAndServe(":8000", nil)
	if err != nil {
		log.Fatal("ListenAndServe:", err)
	}
}
