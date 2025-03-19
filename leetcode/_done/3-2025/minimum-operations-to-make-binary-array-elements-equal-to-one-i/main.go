package main

func minOperations(nums []int) int {
	res := 0
	n := len(nums)
	mem := make([]int, n)
	for idx := 0; idx < n-2; idx++ {
		if mem[idx]%2 != nums[idx]%2 {
			continue
		} else {
			mem[idx]++
			mem[idx+1]++
			mem[idx+2]++
			res++
		}
	}
	if nums[n-3]%2 == mem[n-3]%2 && nums[n-2]%2 == mem[n-2]%2 && nums[n-1]%2 == mem[n-1]%2 {
		res++
	} else if nums[n-3]%2 != mem[n-3]%2 && nums[n-2]%2 != mem[n-2]%2 && nums[n-1]%2 != mem[n-1]%2 {

	} else {
		return -1
	}

	return res
}

func main() {
	_ = minOperations([]int{0, 1, 1, 1, 0, 0})
}
