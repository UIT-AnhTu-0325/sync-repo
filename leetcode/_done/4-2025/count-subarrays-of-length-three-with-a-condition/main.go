package main

func main() {

}

func countSubarrays(nums []int) int {
	res := 0
	for i := 0; i+2 < len(nums); i++ {
		if (nums[i]+nums[i+2])*2 == nums[i+1] {
			res++
		}
	}
	return res
}
