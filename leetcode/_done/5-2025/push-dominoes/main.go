package main

func main() {
	pushDominoes(".L.R...LR..L..")
}

var up = int(1e6)
var down = int(-1e6)

func pushDominoes(dominoes string) string {
	toRight := make([]int, len(dominoes))
	for i := range dominoes {
		if dominoes[i] == 'R' {
			toRight[i] = up
		} else if i > 0 && dominoes[i] != 'L' && toRight[i-1] != 0 {
			toRight[i] = toRight[i-1] - 1
		}
	}

	toLeft := make([]int, len(dominoes))
	for i := len(dominoes) - 1; i >= 0; i-- {
		if dominoes[i] == 'L' {
			toLeft[i] = down
		} else if i < len(dominoes)-1 && dominoes[i] != 'R' && toLeft[i+1] != 0 {
			toLeft[i] = toLeft[i+1] + 1
		}
	}

	res := make([]byte, len(toRight))
	for i := range toRight {
		if toRight[i]+toLeft[i] > 0 {
			res[i] = 'R'
		} else if toRight[i]+toLeft[i] < 0 {
			res[i] = 'L'
		} else {
			res[i] = '.'
		}
	}
	finalString := string(res)
	return finalString
}
