package main

import "sync"
import "fmt"
import "time"

func main() {
	/*
		naturals := make(chan int)
		squares := make(chan int)

		// Counter
		go func() {
			for x := 0; x < 100; x++ {
				naturals <- x
			}
			close(naturals)
		}()

		// Squarer
		go func() {
			for x := range naturals {
				squares <- x * x
			}
			close(squares)
		}()

		// Printer (in main goroutine)
		for x := range squares {
			fmt.Println(x)
		}
	*/

	//	runtime.GOMAXPROCS(1)
	ch := make(chan int, 1)
	for i := 0; i < 10; i++ {
		select {
		case x := <-ch:
			fmt.Println(x) // "0" "2" "4" "6" "8"
		case ch <- i:
		}
	}
	var wg sync.WaitGroup
	wg.Add(1)
	go func() { fmt.Println("haha1") }()
	time.Sleep(time.Second * 5)
	go func() { fmt.Println("haha") }()
	wg.Done()
	wg.Wait()
}
func squarer(out chan<- int, in <-chan int) {
	for v := range in {
		out <- v * v
	}
	close(out)
}
