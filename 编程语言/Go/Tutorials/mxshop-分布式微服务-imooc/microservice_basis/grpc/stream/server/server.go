package main

import (
	"fmt"
	"log"
	"microservice_basis/grpc/stream/proto"
	"net"
	"time"

	"google.golang.org/grpc"
)

const PORT = ":8081"

type Server struct {
}

func (s *Server) GetStream(request *proto.StreamRequestData, response proto.Greeter_GetStreamServer) error {
	log.Println(request.Data)
	ticker := time.NewTicker(1 * time.Second)
	timer := time.NewTimer(10 * time.Second)
	defer func() {
		ticker.Stop()
		timer.Stop()
	}()

	// 注意，如果使用 timer.After
	// 不能将其放在 for select 的 case 中，因为其根本不会发生调用
	// 需要再 for select 前显示的 c := timer.After()
	// 然后将 c 放在 case 中

	for {
		select {
		case <-ticker.C:
			if err := response.Send(&proto.StreamResponseData{
				Data: fmt.Sprintf("%v", time.Now().Unix()),
			}); err != nil {
				return err
			}
		case <-timer.C:
			return nil
		}
	}
}

func (s *Server) PutStream(clientStream proto.Greeter_PutStreamServer) error {
	return nil
}

func (s *Server) AllStream(allStream proto.Greeter_AllStreamServer) error {
	return nil
}

func main() {
	listener, err := net.Listen("tcp", PORT)
	if err != nil {
		log.Fatalln(err)
	}
	s := grpc.NewServer()
	proto.RegisterGreeterServer(s, &Server{})
	if err := s.Serve(listener); err != nil {
		log.Fatalln("failed to serve:", err.Error())
	}
}
