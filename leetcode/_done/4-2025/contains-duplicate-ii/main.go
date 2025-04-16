package main

func main() {

}

func containsNearbyDuplicate(nums []int, k int) bool {
	mem := make(map[int]int)
	for i := range nums {
		if val, ex := mem[nums[i]]; ex {
			if i-val <= k {
				return true
			}
		}
		mem[nums[i]] = i
	}
	return false
}
