package main

import "math"

func main() {
	specialGrid(2)
}

func specialGrid(N int) [][]int {
	m := int(math.Pow(2, float64(N)))
	res := make([][]int, m)
	for i := range res {
		res[i] = make([]int, m)
	}
	if N == 0 {
		return res
	}
	_ = paint(0, m-1, 0, m-1, 0, res)
	return res
}

func paint(startI int, endI int, startJ int, endJ int, crrNum int, grid [][]int) int {
	if endI-startI+1 == 2 && endJ-startJ+1 == 2 {
		grid[startI][endJ] = crrNum
		grid[startI+1][endJ] = crrNum + 1
		grid[startI+1][endJ-1] = crrNum + 2
		grid[startI][endJ-1] = crrNum + 3
		return crrNum + 4
	}
	midI := (endI + startI) / 2
	midJ := (endJ + startJ) / 2

	crrNum = paint(startI, midI, midJ+1, endJ, crrNum, grid)
	crrNum = paint(midI+1, endI, midJ+1, endJ, crrNum, grid)
	crrNum = paint(midI+1, endI, startJ, midJ, crrNum, grid)
	crrNum = paint(startI, midI, startJ, midJ, crrNum, grid)
	return crrNum
}
