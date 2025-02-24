package main

import "strconv"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// StackItem stores both *TreeNode and an integer
type StackItem struct {
	node  *TreeNode
	depth int
}

// Stack implementation
type Stack struct {
	items []StackItem
}

// Push a new item onto the stack
func (s *Stack) Push(node *TreeNode, depth int) {
	s.items = append(s.items, StackItem{node, depth})
}

// Pop an item from the stack
func (s *Stack) Pop() (*TreeNode, int, bool) {
	if len(s.items) == 0 {
		return nil, 0, false // Stack is empty
	}
	last := s.items[len(s.items)-1]
	s.items = s.items[:len(s.items)-1]
	return last.node, last.depth, true
}

// Peek the top item without removing it
func (s *Stack) Peek() (*TreeNode, int, bool) {
	if len(s.items) == 0 {
		return nil, 0, false
	}
	last := s.items[len(s.items)-1]
	return last.node, last.depth, true
}

// IsEmpty checks if the stack is empty
func (s *Stack) IsEmpty() bool {
	return len(s.items) == 0
}

// Size returns the number of elements in the stack
func (s *Stack) Size() int {
	return len(s.items)
}

func recoverFromPreorder(traversal string) *TreeNode {
	if len(traversal) == 0 {
		return nil
	}
	tree := &TreeNode{}
	stack := Stack{}

	keyArr := make([]int, 0)
	heightArr := make([]int, 0)
	crrHeight := 0
	i := 0
	for i < len(traversal) {
		// Step 1: Count the number of '-' to determine depth
		if traversal[i] == '-' {
			crrHeight++
			i++
			continue
		}

		// Step 2: Extract the full number (multi-digit)
		start := i
		for i < len(traversal) && traversal[i] >= '0' && traversal[i] <= '9' {
			i++
		}
		key, _ := strconv.Atoi(traversal[start:i]) // Convert extracted substring to int

		if crrHeight == 0 {
			tree = &TreeNode{Val: key}
			stack.Push(tree, crrHeight)
		}

		// Step 3: Store in maps
		keyArr = append(keyArr, key)
		heightArr = append(heightArr, crrHeight)
		crrHeight = 0
	}

	for i := 0; i < len(keyArr); i++ {
		key := keyArr[i]
		height := heightArr[i]
		if height == 0 {
			continue
		}
		for {
			_, topHeight, _ := stack.Peek()
			if topHeight == height-1 {
				break
			}
			stack.Pop()
		}
		top, _, _ := stack.Peek()

		newNode := &TreeNode{Val: key}
		if top.Left == nil {
			top.Left = newNode
		} else {
			top.Right = newNode
		}
		stack.Push(newNode, height)
	}

	return tree
}

func main() {
	_ = recoverFromPreorder("5-4--4")
}
