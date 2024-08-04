package main

import "fmt"

func sortPeople(names []string, heights []int) []string {
	for i:= 0; i < len(names); i++ {
		for j:= i +1 ; j < len(names); j++ {
			if(heights[i] < heights[j]){
				heights[i], heights[j] = heights[j], heights[i]
				names[i], names[j] = names[j], names[i]
			}
		}
	} 
	
	return names
}

func main() {
	sortPeople([]string{}, []int{})
	fmt.Println("Hello, 世界")
}

