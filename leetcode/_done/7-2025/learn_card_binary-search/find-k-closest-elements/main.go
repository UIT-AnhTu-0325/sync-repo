package main

func main() {
	_ = findClosestElements([]int{1, 2, 3, 4, 5}, 4, 3)
}

func findClosestElements(arr []int, k int, x int) []int {
	left := 0
	right := len(arr) - k
	for left < right {
		mid := (left + right) / 2
		if x-arr[mid] > arr[mid+k]-x {
			left = mid + 1
		} else {
			right = mid
		}
	}
	return arr[left : left+k]
}
