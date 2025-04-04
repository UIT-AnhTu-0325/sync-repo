package main

func calcEquation(equations [][]string, values []float64, queries [][]string) []float64 {
	mem := make(map[string]map[string]float64)
	for idx, item := range equations {
		if _, ex := mem[item[0]]; !ex {
			mem[item[0]] = make(map[string]float64)
		}
		if _, ex := mem[item[1]]; !ex {
			mem[item[1]] = make(map[string]float64)
		}
		mem[item[0]][item[1]] = values[idx]
		mem[item[1]][item[0]] = 1 / values[idx]
	}

	res := make([]float64, 0)

	for _, query := range queries {
		traveled := make(map[string]bool)
		traveled[query[0]] = true
		resItem := calc(mem, traveled, query[1], query[0])
		res = append(res, resItem)
	}

	return res
}

func calc(mem map[string]map[string]float64, traveled map[string]bool, target string, crr string) float64 {
	if val, ex := mem[crr][target]; ex {
		return val
	}
	traveled[crr] = true
	for item := range mem[crr] {
		if traveled[item] {
			continue
		}
		res := calc(mem, traveled, target, item)
		if res > 0 {
			return mem[crr][item] * res
		}
	}
	return -1
}

func main() {
	e := [][]string{{"a", "b"}, {"b", "c"}}
	v := []float64{2.0, 3.0}
	q := [][]string{{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}}
	_ = calcEquation(e, v, q)
}
