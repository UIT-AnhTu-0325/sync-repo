package main

func main() {

}

type Pair struct {
	idx int
	sum int
}

func cPair(i int, s int) Pair {
	return Pair{idx: i, sum: s}
}

func canPartition(nums []int) bool {
	sum := 0
	for i := range nums {
		sum += nums[i]
	}
	if sum%2 != 0 {
		return false
	}
	return calc(nums, 0, 0, sum/2, make(map[Pair]bool))
}

func calc(nums []int, crrIdx int, crrSum int, target int, mem map[Pair]bool) bool {
	if val, ex := mem[cPair(crrIdx, crrSum)]; ex {
		return val
	}
	if crrSum == target {
		return true
	}
	if crrSum > target || crrIdx >= len(nums) {
		return false
	}
	resPick := calc(nums, crrIdx+1, crrSum+nums[crrIdx], target, mem)
	if resPick {
		return true
	}
	mem[cPair(crrIdx+1, crrSum+nums[crrIdx])] = resPick
	resNotPick := calc(nums, crrIdx+1, crrSum, target, mem)
	mem[cPair(crrIdx+1, crrSum)] = resNotPick
	return resNotPick
}
