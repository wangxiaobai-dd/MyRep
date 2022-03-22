package main

import (
	"bufio"
	"fmt"
	"github.com/deckarep/golang-set"
	"github.com/go-echarts/go-echarts/v2/charts"
	"github.com/go-echarts/go-echarts/v2/opts"
	"log"
	"net/http"
	"os"
	"strconv"
	"strings"
)

var matchCount int
var dataMap map[string]map[string]int
var totalMap map[string]int
var dateSet mapset.Set
var dataBar *charts.Bar
var dataLine *charts.Line

func init() {
	dataMap = make(map[string]map[string]int)
	totalMap = make(map[string]int)
	dateSet = mapset.NewSet()
}

func readFile(path string) {
	file, err := os.Open(path)
	if err != nil {
		panic(err)
	}
	defer file.Close()
	scanner := bufio.NewScanner(file)
	count := 0
	for scanner.Scan() {
		line := scanner.Text()
		count++
		getInfo(line)
	}
	log.Println("match count:", matchCount)
	log.Println("total count:", count)

	for name, countMap := range dataMap {
		for date, count := range countMap {
			fmt.Println(name, date, count)
		}
	}

	//fmt.Println("------- total -------")
	/*
		for name, count := range totalMap {
			fmt.Println(name, count)
		}
	*/
	drawBar()
	drawLine()
	fmt.Println("------- finish -------")
}

func drawBar() {
	bar := charts.NewBar()
	bar.SetGlobalOptions(charts.WithTitleOpts(opts.Title{
		Title: "202201-202203 璀璨职业宝石每日新增",
	}))
	var dArray []string

	for d := range dateSet.Iterator().C {
		dArray = append(dArray, d.(string))
	}
	resultBar := bar.SetXAxis(dArray)
	for name, countMap := range dataMap {
		resultBar = resultBar.AddSeries(name, generateBarItems(countMap))
	}
	f, err := os.Create("bar.html")
	if err != nil {
		panic(err)
	}
	resultBar.Render(f)
	dataBar = resultBar
}

func generateBarItems(countMap map[string]int) []opts.BarData {
	items := make([]opts.BarData, 0)

	for d := range dateSet.Iterator().C {
		if count, ok := countMap[d.(string)]; ok {
			items = append(items, opts.BarData{Value: count})
		} else {
			items = append(items, opts.BarData{Value: 0})
		}
	}
	return items
}

func drawLine() {
	line := charts.NewLine()
	line.SetGlobalOptions(charts.WithTitleOpts(opts.Title{
		Title: "202201-202203 璀璨职业宝石每日新增",
	}))
	var dArray []string

	for d := range dateSet.Iterator().C {
		dArray = append(dArray, d.(string))
	}
	resultLine := line.SetXAxis(dArray)
	for name, countMap := range dataMap {
		resultLine = resultLine.AddSeries(name, generateLineItems(countMap))
	}
	f, err := os.Create("line.html")
	if err != nil {
		panic(err)
	}
	resultLine.Render(f)
	dataLine = resultLine
}

func generateLineItems(countMap map[string]int) []opts.LineData {
	items := make([]opts.LineData, 0)

	for d := range dateSet.Iterator().C {
		if count, ok := countMap[d.(string)]; ok {
			items = append(items, opts.LineData{Value: count})
		} else {
			items = append(items, opts.LineData{Value: 0})
		}
	}
	return items
}

func getInfo(line string) {
	matchF := func(c rune) bool {
		if c == ',' {
			return true
		} else {
			return false
		}
	}
	result := strings.FieldsFunc(line, matchF)
	if len(result) == 15 {

		if result[2] == "职业宝石丹" {
			if add, err := strconv.Atoi(result[4]); err == nil {
				countMap, ok := dataMap[result[9]]
				if !ok {
					countMap = make(map[string]int)
				}
				date := result[13][4:]
				countMap[date] += add
				dataMap[result[9]] = countMap
				totalMap[result[9]] += add

				dateSet.Add(date)
			}
		}
		/*
			for index, value := range result {
				fmt.Println("index=", index, "value=", value)
			}
			result[4] add
			result[9] name
			result[13] date
		*/
		matchCount++
	} else {
		fmt.Println("长度异常", result)
	}
}

func httpServer(w http.ResponseWriter, _ *http.Request) {
	if dataLine != nil {
		dataLine.Render(w)
	}
}
func httpServerBar(w http.ResponseWriter, _ *http.Request) {
	if dataBar != nil {
		dataBar.Render(w)
	}
}

func main() {
	readFile("ztlog.txt")
	//http.HandleFunc("/", httpServer)
	//http.HandleFunc("/bar", httpServerBar)
	//http.ListenAndServe(":8080", nil)
}
