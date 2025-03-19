package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func rightSideView(root *TreeNode) []int {
	res := solve(root, 0, []int{})
	return res
}

func solve(root *TreeNode, crrLevel int, res []int) []int {
	if root == nil {
		return res
	}
	if len(res) == crrLevel {
		res = append(res, root.Val)
	} else {
		res[crrLevel] = root.Val
	}
	res = solve(root.Left, crrLevel+1, res)
	res = solve(root.Right, crrLevel+1, res)

	return res
}

func main() {
	_ = rightSideView
}
