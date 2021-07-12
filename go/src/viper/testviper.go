package main

import "fmt"
import "github.com/spf13/viper"

type Host struct {
	Address string
	Port    int
}

func main() {
	fmt.Println("vim-go")
	viper.AutomaticEnv()
	GetEnvInfo("SSH_CONNECTION")
}

func GetEnvInfo(env string) {
	fmt.Println(viper.GetString(env))
}
