package main

func trap(height []int) int {
	n, res := len(height), 0

	fromLeft := []int{height[0]}
	crrMax := height[0]
	for i := 1; i < n; i++ {
		crrMax = _max(height[i], crrMax)
		fromLeft = append(fromLeft, crrMax)
	}

	fromRight := []int{height[len(height)-1]}
	crrMax = height[len(height)-1]
	for i := n - 2; i >= 0; i-- {
		crrMax = _max(height[i], crrMax)
		fromRight = append(fromRight, crrMax)
	}

	for i := 0; i < n; i++ {
		res += _max(_min(fromLeft[i], fromRight[n-i+1])-height[i], 0)
	}

	return res
}

func _min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func _max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	trap([]int{4, 2, 0, 3, 2, 5})
}
