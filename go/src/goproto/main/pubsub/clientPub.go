package main

import (
	"context"
	"log"

	"google.golang.org/grpc"

	pb "goproto/pbservice"
)

func main() {
	conn, err := grpc.Dial("localhost:1234", grpc.WithInsecure())
	if err != nil {
		log.Fatal(err)
	}
	defer conn.Close()

	client := pb.NewPubsubServiceClient(conn)

	_, err = client.Publish(context.Background(), &pb.String{Value: "golang: hello Go"})
	if err != nil {
		log.Fatal(err)
	}
	_, err = client.Publish(context.Background(), &pb.String{Value: "docker: hello Docker"})
	if err != nil {
		log.Fatal(err)
	}
}
