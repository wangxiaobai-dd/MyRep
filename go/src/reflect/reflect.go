package main

import "fmt"
import "reflect"

type ClientValidateReq struct {
	Version int32
	ID      string
	Token   string
	MsgSNo  uint32
}

func Decode(obj interface{}) {
	fmt.Println(reflect.ValueOf(obj))
	fmt.Println((reflect.Indirect(reflect.ValueOf(obj))).Kind())
	v := reflect.Indirect(reflect.ValueOf(obj))
	l := v.NumField()
	for i := 0; i < l; i++ {
		fmt.Println(reflect.Indirect(v.Field(i)).Type())
	}
}

func main() {
	protoType := ClientValidateReq{}
	protoType.Version = 1
	protoType.ID = "500"
	protoType.Token = "1"
	protoType.MsgSNo = 2
	fmt.Println(reflect.TypeOf(protoType).Name())
	fmt.Println(reflect.TypeOf(ClientValidateReq{}).Name())
	Decode(protoType)
}
