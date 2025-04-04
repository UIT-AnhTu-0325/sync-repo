package main

import "math"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func diameterOfBinaryTree(root *TreeNode) int {
	res := math.MinInt
	solve(root, &res)
	return res
}

func solve(root *TreeNode, maxRes *int) int {
	if root == nil {
		return 0
	}
	left := solve(root.Left, maxRes)
	right := solve(root.Right, maxRes)
	crrMax := _max(left, right) + 1
	*maxRes = _max(*maxRes, left+right)
	return crrMax
}

func _max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {

}
