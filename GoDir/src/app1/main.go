package main

import (
	"bytes"
	"fmt"
	"html/template"
	"io/ioutil"
	"log"
	"net/http"
	"net/http/httputil"
	"net/url"
)

type handle struct {
	host string
	port string
}

func (this *handle) showPage(w http.ResponseWriter, r *http.Request) {
	t, _ := template.ParseFiles("main.html")
	t.Execute(w, nil)
}

func (this *handle) forward(w http.ResponseWriter, r *http.Request) {
	remote, _ := url.Parse("http://" + this.host + ":" + this.port)
	bodyBytes, _ := ioutil.ReadAll(r.Body)

	r.Body = ioutil.NopCloser(bytes.NewBuffer(bodyBytes))
	r.ParseForm()
	fmt.Println("server:", r.Form["server"])

	r.Body.Close()
	r.Body = ioutil.NopCloser(bytes.NewBuffer(bodyBytes))

	proxy := httputil.NewSingleHostReverseProxy(remote)
	proxy.ServeHTTP(w, r)
}

func main() {
	serverMap := make(map[string]string)
	serverMap["volvo"] = "127.0.0.1"
	h := &handle{host: "127.0.0.1", port: "8001"}

	http.HandleFunc("/", h.showPage)
	http.HandleFunc("/query", h.forward)
	http.Handle("/static/", http.StripPrefix("/static/", http.FileServer(http.Dir("static"))))
	err := http.ListenAndServe(":8000", nil)
	if err != nil {
		log.Fatal("ListenAndServe:", err)
	}
}
