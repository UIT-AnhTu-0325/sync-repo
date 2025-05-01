package main

import "math"

func main() {

}

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func countNodes(root *TreeNode) int {
	left := calcLeft(root)
	right := calcRight(root)
	if left == right {
		return int(math.Pow(2, float64(left)) - 1)
	}
	return 1 + countNodes(root.Left) + countNodes(root.Right)
}

func calcLeft(root *TreeNode) int {
	if root == nil {
		return 0
	}
	return 1 + calcLeft(root.Left)
}

func calcRight(root *TreeNode) int {
	if root == nil {
		return 0
	}
	return 1 + calcRight(root.Right)
}
