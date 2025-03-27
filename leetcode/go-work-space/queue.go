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
