package main

func main() {

}

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func averageOfLevels(root *TreeNode) []float64 {
	return calc([]*TreeNode{root}, make([]float64, 0))
}

func calc(crrLevel []*TreeNode, avg []float64) []float64 {
	if len(crrLevel) == 0 {
		return avg
	}
	sum := 0
	cnt := 0
	nextLevel := make([]*TreeNode, 0)
	for i := range crrLevel {
		if crrLevel[i] != nil {
			sum += crrLevel[i].Val
			cnt++
			nextLevel = append(nextLevel, crrLevel[i].Left)
			nextLevel = append(nextLevel, crrLevel[i].Right)
		}
	}
	if cnt != 0 {
		avg = append(avg, float64(sum)/float64(cnt))
	}
	avg = calc(nextLevel, avg)
	return avg
}
