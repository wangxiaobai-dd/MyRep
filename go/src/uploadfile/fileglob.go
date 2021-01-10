package main

import (
	"fmt"
	"path/filepath"
	"strings"
)

func main() {
	files, _ := filepath.Glob("Running.*")
	for k, v := range files {
		fmt.Println(strings.Split(v, ".")[1])
		fmt.Println(k, v)
	}
}
