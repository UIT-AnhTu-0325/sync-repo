package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func subtreeWithAllDeepest(root *TreeNode) *TreeNode {
	deep := calcDeep(root)
	deepest := calcDeepest(root, 1, deep)
	return deepest
}

func calcDeepest(root *TreeNode, crrDeep int, deep int) *TreeNode {
	if root == nil {
		return nil
	}
	if root.Left == nil && root.Right == nil {
		if crrDeep == deep {
			return root
		} else {
			return nil
		}
	}
	depestLeft := calcDeepest(root.Left, crrDeep+1, deep)
	depestRight := calcDeepest(root.Right, crrDeep+1, deep)

	if depestLeft != nil && depestRight != nil {
		return root
	} else if depestLeft != nil {
		return depestLeft
	} else if depestRight != nil {
		return depestRight
	} else {
		return nil
	}
}

func calcDeep(root *TreeNode) int {
	if root == nil {
		return 0
	}
	if root.Left == nil && root.Right == nil {
		return 1
	}
	return max(calcDeep(root.Left), calcDeep(root.Right)) + 1
}

func main() {
	_ = subtreeWithAllDeepest(_buildTree([]any{3, 5, 1, 6, 2, 0, 8, nil, nil, 7, 4}))
}

func _buildTree(values []any) *TreeNode {
	if len(values) == 0 || values[0] == nil {
		return nil
	}

	root := &TreeNode{Val: values[0].(int)}
	queue := []*TreeNode{root}
	i := 1

	for i < len(values) {
		current := queue[0]
		queue = queue[1:]

		// Left child
		if i < len(values) && values[i] != nil {
			current.Left = &TreeNode{Val: values[i].(int)}
			queue = append(queue, current.Left)
		}
		i++

		// Right child
		if i < len(values) && values[i] != nil {
			current.Right = &TreeNode{Val: values[i].(int)}
			queue = append(queue, current.Right)
		}
		i++
	}

	return root
}
