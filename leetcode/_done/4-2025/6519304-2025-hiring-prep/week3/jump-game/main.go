package main

import "container/list"

type Queue[T any] struct {
	list *list.List
}

// NewQueue initializes a new queue
func NewQueue[T any]() *Queue[T] {
	return &Queue[T]{list: list.New()}
}

// Enqueue adds an item to the back of the queue
func (q *Queue[T]) Enqueue(value T) {
	q.list.PushBack(value)
}

// Dequeue removes and returns the front item
func (q *Queue[T]) Dequeue() (T, bool) {
	if q.list.Len() == 0 {
		var zero T
		return zero, false
	}
	front := q.list.Front()
	q.list.Remove(front)
	return front.Value.(T), true
}

// IsEmpty checks if the queue is empty
func (q *Queue[T]) IsEmpty() bool {
	return q.list.Len() == 0
}

type Node struct {
	step int
	idx  int
}

func canJumpToSlow(nums []int) bool {
	mem := make(map[int]bool)
	q := NewQueue[Node]()
	q.Enqueue(Node{step: nums[0], idx: 0})
	for !q.IsEmpty() {
		top, _ := q.Dequeue()
		if top.step+top.idx >= len(nums)-1 {
			return true
		}
		for i := top.step; i > 0; i-- {
			if !mem[top.idx+i] {
				mem[top.idx+i] = true
				q.Enqueue(Node{step: nums[top.idx+i], idx: top.idx + i})
			}
		}
	}
	return false
}

func canJump(nums []int) bool {
	max := 0
	for idx, num := range nums {

		if max >= len(nums)-1 {
			return true
		} else if max < idx {
			return false
		}
		max = _max(idx+num, max)
	}
	return false
}

func _max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	_ = canJump([]int{3, 2, 1, 0, 4})
}
