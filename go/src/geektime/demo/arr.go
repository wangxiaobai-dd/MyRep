package main

import (
	"fmt"
)

func Sum(a int, more ...int) int {
	for _, v := range more {
		a += v
	}
	return a
}

func main() {
	var b = [...]int{1, 2, 4: 5}
	var c [2]int // 数组

	var d []int
	var e = make([]int, 3)
	fmt.Println(b)
	for i, c := range []rune("世界abc") {
		fmt.Println(i, c)
	}
	fmt.Println(c, d, e)

	var a []int
	a = append(a, 1)                 // 追加1个元素
	a = append(a, 1, 2, 3)           // 追加多个元素, 手写解包方式
	a = append(a, []int{1, 2, 3}...) // 追加一个切片, 切片需要解包
	fmt.Println(a)

	var x []int
	var i int
	a = append(a, x...)       // 为x切片扩展足够的空间
	copy(a[i+len(x):], a[i:]) // a[i:]向后移动len(x)个位置
	copy(a[i:], x)            // 复制新添加的切片

	N := 0
	a = []int{1, 2, 3}
	a = a[:len(a)-1] // 删除尾部1个元素
	a = a[:len(a)-N] // 删除尾部N个元素

	for i := 0; i < 3; i++ {
		defer func() { fmt.Println(i) }()
	}
}
