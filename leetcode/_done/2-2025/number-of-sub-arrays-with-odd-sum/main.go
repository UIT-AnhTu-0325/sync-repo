package main

func numOfSubarraysSolve(arr []int) (int, int) {
	mod := 1000000007
	if len(arr) == 0 {
		return 0, 0
	}
	if len(arr) == 1 {
		if arr[0]%2 == 0 {
			return 0, 0
		} else {
			return 1, 1
		}
	}
	total, byLast := numOfSubarraysSolve(arr[:len(arr)-1])
	lastItem := arr[len(arr)-1]
	if lastItem%2 == 0 {
		return (total + byLast) % mod, byLast * 2
	} else {
		newCoundOdd := (len(arr) - byLast)
		return (total + newCoundOdd) % mod, newCoundOdd
	}
}

func numOfSubarrays(arr []int) int {
	response, _ := numOfSubarraysSolve(arr)
	return response
}

func theArtOfLife(arr []int) int {
	sum := 0
	odd := 0
	even := 1
	for i := 0; i < len(arr); i++ {
		sum += arr[i]
		if sum&1 == 1 {
			odd++
		} else {
			even++
		}
	}
	return odd * even % (10e9 + 7)
}

func main() {
	_ = numOfSubarrays
	_ = theArtOfLife
}
