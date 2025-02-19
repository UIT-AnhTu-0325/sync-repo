package main

import "fmt"

type CustomStack struct {
	slice   []int
	crrIdx  int
	maxSize int
}

func Constructor(maxSize int) CustomStack {
	return CustomStack{
		slice:   make([]int, maxSize),
		crrIdx:  -1,
		maxSize: maxSize,
	}
}

func (this *CustomStack) Push(x int) {
	if this.crrIdx == this.maxSize-1 {
		return
	}
	this.crrIdx += 1
	this.slice[this.crrIdx] = x
}

func (this *CustomStack) Pop() int {
	if this.crrIdx == -1 {
		return -1
	}
	res := this.slice[this.crrIdx]
	this.crrIdx -= 1
	return res
}

func (this *CustomStack) Increment(k int, val int) {
	min := (k - 1)
	if min > this.crrIdx {
		min = this.crrIdx
	}
	for i := 0; i <= min; i++ {
		this.slice[i] += val
	}
}

func main() {
	obj := Constructor(2)
	obj.Push(1)
	obj.Push(2)
	obj.Push(3)
	res := obj.Pop()
	fmt.Println(res)
	res = obj.Pop()
	fmt.Println(res)
	res = obj.Pop()
	fmt.Println(res)
}
