package main

func main() {

}

func minOperations(nums []int, k int) int {
	mem := make(map[int]bool)
	res := 0
	for i := range nums {
		if nums[i] < k {
			return -1
		}
		if _, ex := mem[nums[i]]; !ex {
			res++
			mem[nums[i]] = true
		}
	}
	res--
	if _, ex := mem[k]; !ex {
		res++
	}
	return res
}
