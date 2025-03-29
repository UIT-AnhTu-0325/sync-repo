package main

func leastInterval(tasks []byte, n int) int {
	mem := make(map[byte]int)

	max := 0
	cntMax := 0

	for _, task := range tasks {
		mem[task]++
		if max == mem[task] {
			cntMax++
		} else if max < mem[task] {
			max = mem[task]
			cntMax = 1
		}
	}

	cntSpace := max - 1
	lenSpace := n - (cntMax - 1)
	emptySlot := cntSpace * lenSpace
	leftTasks := len(tasks) - max*cntMax
	idles := _max(0, emptySlot-leftTasks)

	return len(tasks) + idles
}

func _max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func main() {
	_ = leastInterval([]byte{'B', 'C', 'D', 'A', 'A', 'A', 'A', 'G'}, 2)
}
