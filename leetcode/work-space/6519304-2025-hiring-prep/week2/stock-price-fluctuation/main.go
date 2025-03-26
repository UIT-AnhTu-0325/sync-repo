package main

import (
	"fmt"
	"sort"
)

type StockPrice struct {
	prices      map[int]int
	lastTime    int
	ordered     []int
	priceCounts map[int]int
}

func Constructor() StockPrice {
	return StockPrice{
		prices:      make(map[int]int),
		ordered:     []int{},
		priceCounts: make(map[int]int),
	}
}

func (this *StockPrice) Update(timestamp int, price int) {
	if oldPrice, exists := this.prices[timestamp]; exists {
		this.removeFromOrdered(oldPrice)
	}

	this.prices[timestamp] = price
	this.addToOrdered(price)

	if timestamp > this.lastTime {
		this.lastTime = timestamp
	}
}

func (this *StockPrice) removeFromOrdered(price int) {
	if this.priceCounts[price] > 1 {
		this.priceCounts[price]--
		return
	}

	delete(this.priceCounts, price)
	index := sort.SearchInts(this.ordered, price)
	if index < len(this.ordered) && this.ordered[index] == price {
		this.ordered = append(this.ordered[:index], this.ordered[index+1:]...)
	}
}

func (this *StockPrice) addToOrdered(price int) {
	this.priceCounts[price]++

	if this.priceCounts[price] > 1 {
		return
	}

	index := sort.SearchInts(this.ordered, price)
	this.ordered = append(this.ordered, 0)
	copy(this.ordered[index+1:], this.ordered[index:])
	this.ordered[index] = price
}

func (this *StockPrice) Current() int {
	return this.prices[this.lastTime]
}

func (this *StockPrice) Maximum() int {
	return this.ordered[len(this.ordered)-1]
}

func (this *StockPrice) Minimum() int {
	return this.ordered[0]
}

func main() {
	commands := []string{"StockPrice", "update", "maximum", "current", "minimum", "maximum", "maximum", "maximum", "minimum", "minimum", "maximum", "update", "maximum", "minimum", "update", "maximum", "minimum", "current", "maximum", "update", "minimum", "maximum", "update", "maximum", "maximum", "current", "update", "current", "minimum", "update", "update", "minimum", "minimum", "update", "current", "update", "maximum", "update", "minimum"}
	args := [][]int{{}, {38, 2308}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {47, 7876}, {}, {}, {58, 1866}, {}, {}, {}, {}, {43, 121}, {}, {}, {40, 5339}, {}, {}, {}, {32, 5339}, {}, {}, {43, 6414}, {49, 9369}, {}, {}, {36, 3192}, {}, {48, 1006}, {}, {53, 8013}, {}}

	stock := Constructor()
	results := []interface{}{nil}

	for i := 1; i < len(commands); i++ {
		cmd := commands[i]
		arg := args[i]

		switch cmd {
		case "update":
			stock.Update(arg[0], arg[1])
			results = append(results, nil)
		case "current":
			results = append(results, stock.Current())
		case "maximum":
			results = append(results, stock.Maximum())
		case "minimum":
			results = append(results, stock.Minimum())
		}
	}

	fmt.Println(results)
}
