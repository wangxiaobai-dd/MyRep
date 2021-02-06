package main

import (
	"context"
	"fmt"
	"google.golang.org/grpc"
	hs "goproto/service"
	"log"
)

func main() {
	conn, err := grpc.Dial("localhost:1234", grpc.WithInsecure())
	if err != nil {
		log.Fatal(err)
	}
	defer conn.Close()

	client := hs.NewHelloServiceClient(conn)
	reply, err := client.Hello(context.Background(), &hs.String{Value: "hello"})
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println(reply.GetValue())
}
