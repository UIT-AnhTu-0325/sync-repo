package main

import "math"

func main() {
	minMoves([]string{"BB.", "...", "AA#", "B.."})
}

type Local struct {
	i int
	j int
}

type Key struct {
	i        int
	j        int
	usedPort [26]bool
}

var steps = [][]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}

func minMoves(matrix []string) int {
	port := make([][]Local, 26)
	for i := range port {
		port[i] = make([]Local, 0)
	}
	for i := range matrix {
		for j := range matrix[0] {
			if matrix[i][j] == '.' || matrix[i][j] == '#' {
				continue
			}
			port[int(matrix[i][j]-'A')] = append(port[int(matrix[i][j]-'A')], Local{i: i, j: j})
		}
	}
	visited := make([][]bool, len(matrix))
	for i := range visited {
		visited[i] = make([]bool, len(matrix[0]))
	}
	var usedPort [26]bool
	can, res := calc(matrix, port, visited, usedPort, make(map[Key]int), 0, 0)
	if !can {
		return -1
	}
	return res
}

func calc(matrix []string, port [][]Local, visited [][]bool, usedPort [26]bool, mem map[Key]int, crrI int, crrJ int) (bool, int) {
	if crrI == len(matrix)-1 && crrJ == len(matrix[0])-1 {
		if matrix[crrI][crrJ] != '#' {
			return true, 0
		}
		return false, 0
	}
	if crrI < 0 || crrI >= len(matrix) || crrJ < 0 || crrJ >= len(matrix[0]) || visited[crrI][crrJ] || matrix[crrI][crrJ] == '#' {
		return false, 0
	}
	key := Key{i: crrI, j: crrJ, usedPort: usedPort}
	if val, ex := mem[key]; ex {
		return true, val
	}

	minStep := math.MaxInt
	visited[crrI][crrJ] = true

	for i := range steps {
		canMove, resStep := calc(matrix, port, visited, usedPort, mem, crrI+steps[i][0], crrJ+steps[i][1])
		if canMove {
			minStep = min(minStep, resStep+1)
		}
	}
	if matrix[crrI][crrJ] != '.' && matrix[crrI][crrJ] != '#' {
		crrPort := int(matrix[crrI][crrJ] - 'A')
		if !usedPort[crrPort] {
			for _, val := range port[crrPort] {
				if val.i != crrI || val.j != crrJ {
					usedPort[crrPort] = true
					canTele, resTele := calc(matrix, port, visited, usedPort, mem, val.i, val.j)
					if canTele {
						minStep = min(minStep, resTele)
					}
					usedPort[crrPort] = false
				}
			}
		}
	}

	if minStep != math.MaxInt {
		mem[key] = minStep
		visited[crrI][crrJ] = false

		return true, minStep
	}
	return false, 0
}
