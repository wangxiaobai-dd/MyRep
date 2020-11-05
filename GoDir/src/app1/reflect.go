package main

import (
	"fmt"
	"reflect"
)

func reflect_example(a interface{}) {
	t := reflect.TypeOf(a)
	fmt.Printf("type of a is:%v\n", t)

	k := t.Kind()
	switch k {
	case reflect.Int64:
		fmt.Printf("a is int64\n")
	case reflect.String:
		fmt.Printf("a is string\n")
	}
}

func main() {
	var x int64 = 3
	reflect_example(x)

	var y string = "hello"
	reflect_example(y)
}
