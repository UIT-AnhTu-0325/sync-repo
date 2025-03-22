package main

func countCompleteComponents(n int, edges [][]int) int {
	edgeMaps := make([][]int, n)
	for idx := range edgeMaps {
		edgeMaps[idx] = make([]int, 0)
	}
	for _, edge := range edges {
		edgeMaps[edge[0]] = append(edgeMaps[edge[0]], edge[1])
		edgeMaps[edge[1]] = append(edgeMaps[edge[1]], edge[0])
	}

	visited := make([]bool, n)
	res := 0
	for i := 0; i < n; i++ {
		if visited[i] {
			continue
		}
		cNode, cEdge := solve(edgeMaps, visited, i)
		if cNode*(cNode-1) == cEdge {
			res++
		}
	}
	return res
}

func solve(edgeMaps [][]int, visited []bool, crrNode int) (int, int) {
	if len(edgeMaps[crrNode]) == 0 {
		return 1, 0
	}
	if visited[crrNode] {
		return 0, 0
	}
	visited[crrNode] = true
	totalNode := 1
	totalEdge := len(edgeMaps[crrNode])
	for _, node := range edgeMaps[crrNode] {
		cNode, cEdge := solve(edgeMaps, visited, node)
		totalNode += cNode
		totalEdge += cEdge
	}
	return totalNode, totalEdge
}

func main() {
	_ = countCompleteComponents
}
