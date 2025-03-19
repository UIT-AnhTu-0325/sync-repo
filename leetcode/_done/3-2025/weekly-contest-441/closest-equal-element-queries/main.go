package main

func solveQueries(nums []int, queries []int) []int {
	equalIdxs := make(map[int][]int)
	for idx := range nums {
		_, exists := equalIdxs[nums[idx]]
		if !exists {
			equalIdxs[nums[idx]] = make([]int, 0)
		}
		equalIdxs[nums[idx]] = append(equalIdxs[nums[idx]], idx)
	}
	nearest := make(map[int]int)
	for key := range equalIdxs {
		nearbyIdxs := equalIdxs[key]
		n := len(nums)
		nn := len(nearbyIdxs)
		if len(nearbyIdxs) == 1 {
			nearest[nearbyIdxs[0]] = -1
		} else {
			for i := 0; i < len(nearbyIdxs); i++ {
				crrIdx := nearbyIdxs[i]
				leftNear := nearbyIdxs[(i-1+nn)%nn]
				rightNear := nearbyIdxs[(i+1)%nn]

				leftDistance := minDistanceCircular(n, leftNear, crrIdx)
				rightDistance := minDistanceCircular(n, rightNear, crrIdx)
				nearest[crrIdx] = _min(leftDistance, rightDistance)
			}
		}
	}

	result := make([]int, 0)
	for idx := range queries {
		result = append(result, nearest[queries[idx]])
	}

	return result
}

func minDistanceCircular(n, i, j int) int {
	forward := (j - i + n) % n
	backward := (i - j + n) % n
	return min(forward, backward)
}

func _min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func _abs(n int) int {
	if n < 0 {
		return -n
	}
	return n
}

func main() {
	nums := []int{6, 12, 17, 9, 16, 7, 6}
	queries := []int{5, 6, 0, 4}
	_ = solveQueries(nums, queries)
}
