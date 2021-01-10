package main

import (
	"flag"
	"os"
)

var name string

var cmdLine = flag.NewFlagSet("question", flag.PanicOnError)

func init() {
	/*
		flag.StringVar(&name, "name", "everyone", "The greeting object.")
		flag.Usage = func() {
			fmt.Fprint(os.Stderr, "Usage")
			flag.PrintDefaults()
		}
	*/
	cmdLine.StringVar(&name, "name", "everyone", "The greeting object.")
}

func main() {
	// flag.Parse()
	cmdLine.Parse(os.Args[1:])
	hello(name)
}
