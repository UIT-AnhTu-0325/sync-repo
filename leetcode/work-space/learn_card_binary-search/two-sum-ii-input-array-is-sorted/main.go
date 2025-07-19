package main

func main() {
	twoSum([]int{-1, 0}, -1)
}

func twoSum(numbers []int, target int) []int {
	for idx, num := range numbers {
		start := idx + 1
		end := len(numbers) - 1
		if start > end {
			continue
		}
		for start <= end {
			mid := (start + end) / 2
			if num+numbers[mid] == target {
				return []int{idx + 1, mid + 1}
			} else if num+numbers[mid] < target {
				start = mid + 1
			} else {
				end = mid - 1
			}
		}
	}
	return []int{-1, -1}
}
