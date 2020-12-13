package main

import (
	"fmt"
	"github.com/beevik/etree"
)

func main() {

	doc := etree.NewDocument()
	//doc.ReadSettings.CharsetReader =

	if err := doc.ReadFromFile("a.xml"); err != nil {
		panic(err)
	}
	root := doc.SelectElement("servers")
	fmt.Println("root:", root.Tag)
	for _, s := range root.SelectElements("server") {
		fmt.Println("CHILD element:", s.Tag)
	}
	mysql := root.SelectElement("mysql")
	fmt.Println(mysql.Text())
}
