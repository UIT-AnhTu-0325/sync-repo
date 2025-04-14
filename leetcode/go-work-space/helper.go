package main

import (
	"slices"
	"sort"
)

type Pair struct {
	first  int
	second int
}

func _createPairs(firsts []int, seconds []int, quantity int) []Pair {
	pairs := make([]Pair, quantity)
	for i := 0; i < quantity; i++ {
		pairs[i] = Pair{first: firsts[i], second: seconds[i]}
	}
	return pairs
}

func _sortPair(firsts []int, seconds []int) []Pair {
	quantity := len(firsts)
	pairs := _createPairs(firsts, seconds, quantity)

	sort.Slice(pairs, func(i, j int) bool {
		return pairs[i].second > pairs[j].second
	})
	return pairs
}

func _max(nums ...int) int {
	return slices.Max(nums)
}

func _min(nums ...int) int {
	return slices.Min(nums)
}

func _abs(n int) int {
	if n < 0 {
		return -n
	}
	return n
}

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
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
