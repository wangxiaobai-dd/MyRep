package main

import (
	"fmt"
	"sync/atomic"
	"unsafe"
)

type node struct {
	a int
}

func main() {
	var tail unsafe.Pointer
	var head unsafe.Pointer

	n := &node{a: 1}
	head = unsafe.Pointer(n)
	if tail != nil {
		fmt.Println("tail is not nil")
	} else {
		fmt.Println("tail is nil")
	}

	if head != nil {
		fmt.Println("head is not nil")
	} else {
		fmt.Println("head is nil")
	}

	//flag := atomic.CompareAndSwapPointer(&head, head, tail)

	if tail != nil {
		fmt.Println("tail is not nil")
	} else {
		fmt.Println("tail is nil")
	}

	if head != nil {
		fmt.Println("head is not nil")
	} else {
		fmt.Println("head is nil")
	}

	n1 := &node{1}
	n2 := &node{2}

	head = unsafe.Pointer(&n1) //1
	tail = unsafe.Pointer(&n2) //2
	fmt.Println(head, tail)    // 2, 2
	flag := atomic.CompareAndSwapPointer(&head, head, tail)
	fmt.Println("after swap", flag)
	fmt.Println(head, tail)                       // 2, 2
	fmt.Println((*node)(head).a, (*node)(tail).a) // 2, 2
	fmt.Println(n1.a, n2.a)                       // 2, 2
}
