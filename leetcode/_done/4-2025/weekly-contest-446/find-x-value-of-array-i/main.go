package main

func main() {

}

func resultArray(nums []int, k int) []int64 {
	result := make([]int64, k)

	dp := make([]int64, k)

	for _, num := range nums {
		newDp := make([]int64, k)

		numMod := num % k

		newDp[numMod]++

		for modVal := 0; modVal < k; modVal++ {
			newMod := (modVal * numMod) % k
			newDp[newMod] += dp[modVal]
		}

		for modVal := 0; modVal < k; modVal++ {
			result[modVal] += newDp[modVal]
		}

		dp = newDp
	}

	return result
}
