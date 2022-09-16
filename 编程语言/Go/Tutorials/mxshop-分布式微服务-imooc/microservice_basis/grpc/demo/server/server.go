package main

import (
	"context"
	"log"
	"microservice_basis/grpc/demo/proto"
	"net"

	"google.golang.org/grpc"
)

type Server struct{}

func (s *Server) SayHello(ctx context.Context, request *proto.HelloRequest) (*proto.HelloReply, error) {
	return &proto.HelloReply{
		Message: "Hello " + request.Name,
	}, nil
}

func main() {
	s := grpc.NewServer()
	proto.RegisterGreeterServer(s, &Server{})
	listener, err := net.Listen("tcp", "127.0.0.1:8080")
	if err != nil {
		log.Fatalln("failed to listen:", err.Error())
	}
	if err := s.Serve(listener); err != nil {
		log.Fatalln("failed to serve:", err.Error())
	}
}
