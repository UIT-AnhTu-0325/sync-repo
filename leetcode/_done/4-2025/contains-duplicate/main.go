package main

func main() {

}

func containsDuplicate(nums []int) bool {
	mem := make(map[int]int)
	for i := range nums {
		if _, ex := mem[nums[i]]; ex {
			return true
		}
		mem[nums[i]] = 100
	}
	return false
}
