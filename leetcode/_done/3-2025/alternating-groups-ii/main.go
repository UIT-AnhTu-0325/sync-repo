package main

func numberOfAlternatingGroups(colors []int, k int) int {
	start, end, count := 0, 0, 0
	n := len(colors)
	for start < n {
		end++
		if colors[end%n] == colors[(end-1)%n] {
			start = end
		}
		if end-start+1 == k {
			count++
			start++
		}
	}

	return count
}

func main() {
	_ = numberOfAlternatingGroups
}
