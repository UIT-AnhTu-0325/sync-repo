package main

func attackIsland(m, n int, grid [][]byte) {
	if m < 0 || n < 0 || m >= len(grid) || n >= len(grid[0]) || grid[m][n] != '1' {
		return
	}
	grid[m][n] = '2'
	attackIsland(m-1, n, grid)
	attackIsland(m+1, n, grid)
	attackIsland(m, n-1, grid)
	attackIsland(m, n+1, grid)
}

func numIslands(grid [][]byte) int {
	if len(grid) == 0 {
		return 0
	}
	count := 0
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			if grid[i][j] == '1' {
				count++
				attackIsland(i, j, grid)
			}
		}
	}
	return count
}

func main() {

}
