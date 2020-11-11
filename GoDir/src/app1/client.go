package main

import (
	"fmt"
	"log"
	"net/http"
	"os/exec"
)

func queryLog(w http.ResponseWriter, r *http.Request) {
	r.ParseForm()
	fmt.Println("server:", r.Form["server"])
	cmd := exec.Command("/bin/bash", "-c", "grep g main.go")
	output, err := cmd.Output()
	if err != nil {
		fmt.Println("Execute Command failed:" + err.Error())
	} else {
		fmt.Fprintf(w, "Hello astaxie!")
		fmt.Printf("finished with output:\n%s", string(output))
	}
}

func main() {
	http.HandleFunc("/query", queryLog)
	err := http.ListenAndServe(":8001", nil)
	if err != nil {
		log.Fatal("ListenAndServe:", err)
	}
}
