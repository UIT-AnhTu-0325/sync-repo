package main

func lenLongestFibSubseq(arr []int) int {
	n := len(arr)
	res := 0
	mem := make([][]int, n)
	indexOf := make(map[int]int, len(arr))
	for i, v := range arr {
		indexOf[v] = i
	}

	for i := range mem {
		mem[i] = make([]int, n)
		for j := range mem[i] {
			mem[i][j] = -1
		}
	}
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			res = max(findLen(arr, mem, indexOf, i, j), res)
		}
	}
	if res <= 2 {
		return 0
	}
	return res
}

func findLen(arr []int, mem [][]int, indexOf map[int]int, fir int, sec int) int {
	if mem[fir][sec] != -1 {
		return mem[fir][sec]
	}
	nextIdx, exists := indexOf[arr[fir]+arr[sec]]
	if !exists {
		return 2
	}
	len := 1 + findLen(arr, mem, indexOf, sec, nextIdx)
	mem[fir][sec] = len
	return len
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	_ = lenLongestFibSubseq
}
