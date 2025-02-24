package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// Stack using slice
type Stack struct {
	items []*TreeNode
}

// Push a node onto the stack
func (s *Stack) Push(node *TreeNode) {
	s.items = append(s.items, node)
}

// Pop a node from the stack
func (s *Stack) Pop() (*TreeNode, bool) {
	if len(s.items) == 0 {
		return nil, false // Stack is empty
	}
	last := s.items[len(s.items)-1]
	s.items = s.items[:len(s.items)-1]
	return last, true
}

// Peek the top node without removing it
func (s *Stack) Peek() (*TreeNode, bool) {
	if len(s.items) == 0 {
		return nil, false
	}
	return s.items[len(s.items)-1], true
}

// IsEmpty checks if the stack is empty
func (s *Stack) IsEmpty() bool {
	return len(s.items) == 0
}

// Size returns the number of elements in the stack
func (s *Stack) Size() int {
	return len(s.items)
}

func constructFromPrePost(preorder []int, postorder []int) *TreeNode {
	if len(preorder) == 0 {
		return nil
	}
	postIdx := make(map[int]int)
	for i := 0; i < len(postorder); i++ {
		postIdx[postorder[i]] = i
	}
	tree := &TreeNode{Val: preorder[0]}

	stack := Stack{}
	stack.Push(tree)

	for i := 1; i < len(preorder); i++ {
		top, _ := stack.Peek()
		if postIdx[preorder[i]] < postIdx[top.Val] {
			newNode := &TreeNode{Val: preorder[i]}
			if top.Left == nil {
				top.Left = newNode
			} else {
				top.Right = newNode
			}
			stack.Push(newNode)
		} else {
			stack.Pop()
			i -= 1
		}
	}

	return tree
}

func main() {
	_ = constructFromPrePost
}
