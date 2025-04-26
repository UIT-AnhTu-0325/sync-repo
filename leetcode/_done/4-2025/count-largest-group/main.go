package main

func main() {

}

func countLargestGroup(n int) int {
	hashMap := make(map[int]int)
	maxValue := 0
	for i := 1; i <= n; i++ {
		key := 0
		i0 := i
		for i0 > 0 {
			key += i0 % 10
			i0 /= 10
		}
		hashMap[key]++
		maxValue = max(maxValue, hashMap[key])
	}

	count := 0
	for _, value := range hashMap {
		if value == maxValue {
			count++
		}
	}
	return count
}
