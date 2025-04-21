package main

func main() {

}

func maximumPossibleSize(nums []int) int {
	crr := nums[0]
	res := 1
	for i := 1; i < len(nums); i++ {
		if nums[i] >= crr {
			res++
			crr = nums[i]
		}
	}
	return res
}
