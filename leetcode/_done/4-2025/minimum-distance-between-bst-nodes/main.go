package main

import "math"

func main() {

}

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func minDiffInBST(root *TreeNode) int {
	return calc(root, make([]int, 0), math.MaxInt)
}

func calc(root *TreeNode, val []int, crrMin int) int {
	if root == nil {
		return crrMin
	}
	for i := range val {
		if _abs(val[i]-root.Val) < crrMin {
			crrMin = _abs(val[i] - root.Val)
		}
	}
	val = append(val, root.Val)
	left := calc(root.Left, val, crrMin)
	return calc(root.Right, val, left)
}

func _abs(n int) int {
	if n < 0 {
		return -n
	}
	return n
}
