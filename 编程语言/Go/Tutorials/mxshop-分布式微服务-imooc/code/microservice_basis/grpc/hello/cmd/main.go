package main

import (
	"encoding/json"
	"fmt"
	pb "microservice_basis/grpc/hello"

	"google.golang.org/protobuf/proto"
)

type Hello struct {
	Name    string   `json:"name"`
	Age     int      `json:"age"`
	Courses []string `json:"courses"`
}

func main() {
	request := pb.HelloRequest{
		Name:    "iris",
		Age:     18,
		Courses: []string{"go", "gin", "microservice"},
	}
	p, _ := proto.Marshal(&request) // protobuf 的原理
	fmt.Println(string(p))
	newRequest := new(pb.HelloRequest)
	proto.Unmarshal(p, newRequest)
	fmt.Println(newRequest.Name, newRequest.Age, newRequest.Courses)

	jh := Hello{
		Name:    "rick",
		Age:     18,
		Courses: []string{"go", "gin", "microservice"},
	}
	p, _ = json.Marshal(&jh)
	fmt.Println(string(p))
}
