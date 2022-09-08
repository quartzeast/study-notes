package main

import "flag"

var IP = flag.String("ip", global.ServerConfig.ConsulConfig.ServerHost, "ip address")
var Port = flag.Int("port", 0, "port")

func main() {

}
