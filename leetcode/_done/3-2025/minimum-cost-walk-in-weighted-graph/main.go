package main

type Node struct {
	node int
	val  int
}

func minimumCost(n int, edges [][]int, query [][]int) []int {
	connects := make(map[int][]Node)
	for _, edge := range edges {
		if item, exi := connects[edge[0]]; exi {
			connects[edge[0]] = append(item, Node{node: edge[1], val: edge[2]})
		} else {
			connects[edge[0]] = []Node{{node: edge[1], val: edge[2]}}
		}
		if item, exi := connects[edge[1]]; exi {
			connects[edge[1]] = append(item, Node{node: edge[0], val: edge[2]})
		} else {
			connects[edge[1]] = []Node{{node: edge[0], val: edge[2]}}
		}
	}

	groups := make([]int, n)
	visited := make([]bool, n)
	groupCosts := make([]int, 0)
	groupIdx := 0

	for i := 0; i < n; i++ {
		cost := solve(groups, groupIdx, connects, visited, i, -1)
		groupCosts = append(groupCosts, cost)
		groupIdx++
	}

	res := make([]int, 0)
	for _, item := range query {
		if groups[item[0]] == groups[item[1]] {
			res = append(res, groupCosts[groups[item[0]]])
		} else {
			res = append(res, -1)
		}
	}

	return res
}

func solve(groups []int, groupIdx int, connects map[int][]Node, visited []bool, crrItem int, crrCost int) int {
	if visited[crrItem] {
		return -1
	}
	visited[crrItem] = true
	groups[crrItem] = groupIdx
	con, ex := connects[crrItem]
	if !ex {
		return -1
	}
	for _, node := range con {
		if crrCost == -1 {
			crrCost = node.val
		} else {
			crrCost &= node.val
		}
		nodeCost := solve(groups, groupIdx, connects, visited, node.node, crrCost)

		if nodeCost != -1 {
			crrCost &= nodeCost
		}
	}
	return crrCost
}

func main() {
	_ = minimumCost(5, [][]int{{0, 1, 7}, {1, 3, 7}, {1, 2, 1}}, [][]int{{0, 3}, {0, 4}})
}
