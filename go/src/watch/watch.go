package main

import (
	"github.com/fsnotify/fsnotify"
	"log"
	"os"
	"path/filepath"
)

func main() {
	watchdir := os.Args[1]
	watcher, err := fsnotify.NewWatcher()
	if err != nil {
		log.Fatal(err)
	}
	defer watcher.Close()

	done := make(chan bool)
	go func() {
		for {
			select {
			case event, ok := <-watcher.Events:
				if !ok {
					return
				}
				//log.Println("event:", event)
				if event.Op&fsnotify.Write == fsnotify.Write && filepath.Ext(event.Name) == ".xml" {
					log.Println(filepath.Ext(event.Name))
					log.Println("modified file:", event.Name)
				}
			case err, ok := <-watcher.Errors:
				if !ok {
					return
				}
				log.Println("error:", err)
			}
		}
	}()

	err = watcher.Add(watchdir)
	err = watcher.Add(watchdir)
	err = watcher.Add(watchdir)
	err = watcher.Add(watchdir)
	err = watcher.Add(watchdir)
	if err != nil {
		log.Fatal(err)
	}
	<-done
}
