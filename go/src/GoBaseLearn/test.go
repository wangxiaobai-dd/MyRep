package main

import (
	"fmt"
	"io"
	"os"
	"reflect"
	"sync"
)

type Point struct {
	X, Y float64
}

type ColorPoint struct {
	Point
	Color float64
}

func (p *Point) ScaleBy(factor float64) {

}

// 匿名结构体
var cache = struct {
	sync.Mutex
	mapping map[string]string
}{mapping: make(map[string]string)}

func Lookup(key string) {

}

func (p *Point) Launch(q Point) {

}

type Reader interface {
	Reader(p []byte) (n int, err error)
}

//time.AfterFunc(time.Second, r.Launch)

func main() {
	fmt.Println("vim-go")
	p := Point{1, 2}
	p.ScaleBy(2)
	var op func(p *Point, q Point)
	op = (*Point).Launch
	op(&p, p)

	var w io.Writer
	w = os.Stdout
	rw := w.(io.ReadWriter)
	fmt.Println(reflect.TypeOf(rw)) // os.File

	w = os.Stdout
	f := w.(*os.File)
	fmt.Println(reflect.TypeOf(f)) // os.File
}
