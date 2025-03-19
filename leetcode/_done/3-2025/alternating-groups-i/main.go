package main

func numberOfAlternatingGroups(colors []int) int {
	res := 0
	n := len(colors)
	for idx := 0; idx < len(colors); idx++ {
		if colors[idx] != colors[(idx+n-1)%n] && colors[(idx+n-1)%n] != colors[(idx+n-2)%n] {
			res++
		}
	}
	return res
}

func main() {
	_ = numberOfAlternatingGroups
}
