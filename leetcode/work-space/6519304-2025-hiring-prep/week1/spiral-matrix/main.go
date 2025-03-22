package main

func spiralOrder(matrix [][]int) []int {
	m := len(matrix)
	n := len(matrix[0])
	edges := []int{0, n - 1, m - 1, 0}
	steps := [][]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}
	crrStepIdx := 0
	res := make([]int, 0)
	i, j := 0, 0

	for edges[0] <= edges[2] || edges[1] >= edges[3] {
		crrStep := steps[crrStepIdx]
		for i >= edges[0] && i <= edges[2] && j <= edges[1] && j >= edges[3] {
			res = append(res, matrix[i][j])
			i += crrStep[0]
			j += crrStep[1]
		}
		i -= crrStep[0]
		j -= crrStep[1]
		switch crrStepIdx {
		case 0:
			i++
			edges[0]++
		case 1:
			j--
			edges[1]--
		case 2:
			i--
			edges[2]--
		case 3:
			j++
			edges[3]++
		}
		crrStepIdx += 1
		crrStepIdx %= 4
	}
	return res
}

func main() {
	_ = spiralOrder([][]int{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}})
}
