package main

func minCosts(cost []int) []int {
	res := []int{cost[0]}
	for idx := 1; idx < len(cost); idx++ {
		res = append(res, _min(res[idx-1], cost[idx]))
	}
	return res
}

func _min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
