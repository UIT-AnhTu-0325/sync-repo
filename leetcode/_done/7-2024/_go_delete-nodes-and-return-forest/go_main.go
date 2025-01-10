package main

import "fmt"

type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func solve(root *TreeNode, parent *TreeNode, res *[]*TreeNode, to_delete[]int){
	if root == nil {
		return
	}
	isDelete := false
	for _, del := range to_delete {
		if del == root.Val {
			isDelete = true;
			break
		}
	}

	if !isDelete {
		if parent == nil {
			*res = append(*res, root)
		}
		solve(root.Left, root, res, to_delete);
		solve(root.Right, root, res, to_delete);
	}else{
		if parent != nil {
			if parent.Left != nil && parent.Left.Val == root.Val {
				parent.Left = nil
			}
			if parent.Right != nil && parent.Right.Val == root.Val {
				parent.Right = nil
			}
		}
		solve(root.Left, nil, res, to_delete)
		solve(root.Right, nil, res, to_delete)
	}
}

func delNodes(root *TreeNode, to_delete []int) []*TreeNode {
	var res []*TreeNode
	solve(root, nil, &res, to_delete);
    return res;
}

func main() {
	fmt.Println("Hello, It's me")
	delNodes(nil, []int{})
}

