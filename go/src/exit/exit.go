package main

import "fmt"
import "os"
import "os/signal"
import "syscall"

func main() {
	fmt.Println("vim-go")

	exitChan := make(chan int)
	signalChan := make(chan os.Signal, 1)
	go func() {
		<-signalChan
		exitChan <- 1
	}()
	signal.Notify(signalChan, syscall.SIGINT, syscall.SIGTERM)
	//....
	<-exitChan
}
