package main

func main() {

}

func numberOfArrays(differences []int, lower int, upper int) int {
	crr := 0
	difMin := 0
	difMax := 0
	for i := range differences {
		crr += differences[i]
		difMin = min(difMin, crr)
		difMax = max(difMax, crr)
	}

	return max(upper-lower+1-(difMax-difMin), 0)
}
