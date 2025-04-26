package main

func main() {

}

func numRabbits(answers []int) int {
	mem := make(map[int]int)
	for i := range answers {
		mem[answers[i]]++
	}
	res := 0
	for i := range mem {
		res += (mem[i] / (i + 1)) * (i + 1)
		if mem[i]%(i+1) != 0 {
			res += i
			res++
		}
	}
	return res
}
