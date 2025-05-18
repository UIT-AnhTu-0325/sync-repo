package main

func main() {

}

func smallestIndex(nums []int) int {
	for i := range nums {
		sum := 0
		for nums[i] > 0 {
			sum += nums[i] % 10
			nums[i] /= 10
		}
		if i == sum {
			return i
		}
	}
	return -1
}
