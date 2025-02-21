package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type FindElements struct {
	values map[int]struct{}
}

func Constructor(root *TreeNode) FindElements {
	findElements := FindElements{
		values: make(map[int]struct{}),
	}
	findElements.Travel(root, 0)
	return findElements
}

func (this *FindElements) Travel(root *TreeNode, crrval int) {
	if root == nil {
		return
	}
	this.values[crrval] = struct{}{}
	this.Travel(root.Left, crrval*2+1)
	this.Travel(root.Right, crrval*2+2)
	return
}

func (this *FindElements) Find(target int) bool {
	_, exists := this.values[target]
	return exists
}
