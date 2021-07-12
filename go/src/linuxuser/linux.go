package main

import "fmt"
import "os/user"
import "log"

func main() {
	fmt.Println("vim-go")
	u, _ := user.Current()
	log.Printf("Username ", u.Username, u.HomeDir)
}
