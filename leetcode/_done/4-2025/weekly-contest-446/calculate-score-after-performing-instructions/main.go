package main

func main() {

}

func calculateScore(instructions []string, values []int) int64 {
	idx := 0
	scr := int64(0)
	n := len(values)
	visisted := make([]bool, n+1)

	for idx < n && idx >= 0 && !visisted[idx] {
		visisted[idx] = true
		if instructions[idx] == "add" {
			scr += int64(values[idx])
			idx++
		} else {
			idx += values[idx]
		}
	}
	return scr
}
