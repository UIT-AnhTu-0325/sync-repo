package main

func main() {

}

func countPairs(nums []int, k int) int {
	n := len(nums)
	res := 0
	for i := 0; i < n-1; i++ {
		for j := i + 1; j < n; j++ {
			if (i*j)%k == 0 && nums[i] == nums[j] {
				res++
			}
		}
	}
	return res
}
