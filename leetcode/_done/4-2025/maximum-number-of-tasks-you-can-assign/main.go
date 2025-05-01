package main

import "sort"

func main() {
	maxTaskAssign([]int{5, 9, 8, 5, 9}, []int{1, 6, 4, 2, 6}, 1, 5)
}

func maxTaskAssign(tasks []int, workers []int, pills int, strength int) int {
	sort.Ints(tasks)
	sort.Ints(workers)

	iTask := len(tasks) - 1
	iWorker := len(workers) - 1

	res := 0

	for iWorker >= 0 && iTask >= 0 {
		if workers[iWorker] >= tasks[iTask] {
			iTask--
			iWorker--
			res++
		} else if workers[iWorker]+strength >= tasks[iTask] && pills > 0 {
			pills--
			iTask--
			iWorker--
			res++
		} else {
			iTask--
		}
	}
	return res
}
