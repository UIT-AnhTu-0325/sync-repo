package main

func main() {
	_ = findClosestElements([]int{1, 2, 3, 4, 5}, 4, 3)
}

func findClosestElements(arr []int, k int, x int) []int {
	left := 0
	right := len(arr) - 1

	for left < right {
		mid := left + (right-left)/2
		if _abs(left-x) <= _abs(right-x) {
			right = mid
		} else {
			left = mid
		}
	}
	return arr[left : right+1]
}

func _abs(n int) int {
	if n < 0 {
		return -n
	}
	return n
}
