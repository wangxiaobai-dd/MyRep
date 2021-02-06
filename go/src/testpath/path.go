package main

import (
	"fmt"
	"log"
	//	"path"
	"path/filepath"
)

func main() {
	//	fmt.Println(path.Clean("./a/b/../"))
	//	fmt.Println(filepath.EvalSymlinks("./a/b/../"))
	fmt.Println(filepath.Dir("~gocode/src/go_note/package/path/a.xml"))
	fmt.Println(filepath.Dir(filepath.Dir("/home/quanju/allzone/zConfig/a.xml")))
	filepathNames, err := filepath.Glob(filepath.Join("./", "Running*"))
	if err != nil {
		log.Fatal(err)
	}

	str := filepathNames[0]
	fmt.Println(str) //打印path

	var name []string
	copy(name, filepathNames)
	name = append(name, str)
	for i := range filepathNames {
		fmt.Println(filepathNames[i]) //打印path
	}

	fmt.Println("vim-go")
}
