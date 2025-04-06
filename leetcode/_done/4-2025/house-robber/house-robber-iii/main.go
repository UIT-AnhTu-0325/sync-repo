package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type Mem struct {
	Node    *TreeNode
	CanPick bool
}

func CMem(n *TreeNode, p bool) Mem {
	return Mem{Node: n, CanPick: p}
}

func rob(root *TreeNode) int {
	return calc(root, true, make(map[Mem]int))
}

func calc(root *TreeNode, canPickMe bool, mem map[Mem]int) int {
	if root == nil {
		return 0
	}
	if val, ex := mem[CMem(root, canPickMe)]; ex {
		return val
	}
	pickRoot := 0
	if canPickMe {
		pickRoot = calc(root.Left, false, mem) + calc(root.Right, false, mem) + root.Val
	}
	notPicRoot := calc(root.Left, true, mem) + calc(root.Right, true, mem)
	res := max(pickRoot, notPicRoot)
	mem[CMem(root, canPickMe)] = res
	return res
}

func main() {
	_ = rob
}
