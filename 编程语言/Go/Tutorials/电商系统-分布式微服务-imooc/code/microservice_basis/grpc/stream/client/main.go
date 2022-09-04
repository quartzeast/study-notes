package main

import (
	"context"
	"log"
	"microservice_basis/grpc/stream/proto"

	"google.golang.org/grpc"
	"google.golang.org/grpc/credentials/insecure"
)

func main() {
	conn, err := grpc.Dial("127.0.0.1:8081", grpc.WithTransportCredentials(insecure.NewCredentials()))
	if err != nil {
		log.Fatalln(err)
	}
	defer conn.Close()

	c := proto.NewGreeterClient(conn)
	response, _ := c.GetStream(context.Background(), &proto.StreamRequestData{Data: "hello world"})
	for {
		a, err := response.Recv()
		if err != nil {
			log.Fatalln(err)
		}
		log.Println(a)
	}
}
