package main

func canChange(start string, target string) bool {
	srcL, desL, havePenR := 0, 0, 0
	for i := 0; i < len(start); i++ {
		if start[i] == 'L' {
			srcL++
		}
		if target[i] == 'L' {
			desL++
		}
		if start[i] == 'R' || target[i] == 'R' || i == len(start)-1 {
			if srcL != desL {
				return false
			}
			if start[i] == 'R' {
				havePenR++
			}
			if target[i] == 'R' && havePenR > 0 {
				havePenR--
			} else if target[i] == 'R' && havePenR <= 0 {
				return false
			}
		}
	}
	srcR, desR, havePenL := 0, 0, 0
	for i := len(start) - 1; i >= 0; i-- {
		if start[i] == 'R' {
			srcR++
		}
		if target[i] == 'R' {
			desR++
		}
		if start[i] == 'L' || target[i] == 'L' || i == 0 {
			if srcR != desR {
				return false
			}
			if start[i] == 'L' {
				havePenL++
			}
			if target[i] == 'L' && havePenL > 0 {
				havePenL--
			} else if target[i] == 'L' && havePenL <= 0 {
				return false
			}
		}
	}
	return true
}

func main() {
	//_ = canChange("R__L", "_LR_")
	// _ = canChange("_L__R__R_", "L______RR")
	_ = canChange("R_L__R__R_", "_L______RR")
}
