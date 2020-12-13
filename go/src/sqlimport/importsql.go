package main

import (
	"database/sql"
	"fmt"
	"github.com/go-sql-driver/mysql"
)

var db *sql.DB

func init() {
	var err error
	db, err = sql.Open("mysql", "ubuntu:Qwe1239550@/testgo")
	if err != nil {
		panic(err)
	}
	//defer db.Close()
}

func main() {
	fmt.Println("vim-go")
	mysql.RegisterLocalFile("aaa")
	//sql := "select * from gogotable"
	sql2 := "select * from gogotable order by id DESC limit 1"
	sql := "load data local infile 'aaa' into table gogotable"
	ret, err := db.Exec(sql)
	fmt.Println(ret.RowsAffected())
	{
		ret, _ := db.Query(sql2)
		for ret.Next() {
			var id int64
			if e := ret.Scan(&id); e != nil {
				fmt.Println(e)
			}
			fmt.Println(id)
		}
	}
	if err != nil {
		fmt.Println(1)
		fmt.Println(err)
	}
}
