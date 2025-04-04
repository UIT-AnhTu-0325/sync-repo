package main

import "math"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func solve(root *TreeNode, crrMax *int) int {
	if root == nil {
		return 0
	}
	leftVal := solve(root.Left, crrMax)
	rightVal := solve(root.Right, crrMax)
	leftMax := _max(0, leftVal)
	rightMax := _max(0, rightVal)
	max := leftMax + rightMax + root.Val
	*crrMax = _max(max, *crrMax)

	return root.Val + _max(0, _max(leftMax, rightMax))
}

func _max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func maxPathSum(root *TreeNode) int {
	max := math.MinInt
	solve(root, &max)
	return max
}

func main() {

}
