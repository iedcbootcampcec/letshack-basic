package main

import "fmt"

func bubbleSort(arr []int) []int {
	for range arr {
		for j, _ := range arr {
			if j >= len(arr) - 1 {
				break
			}
			if arr[j] > arr[j+1] {
				arr[j+1], arr[j] = arr[j], arr[j+1]
			}
		}
	}

	return arr
}

func main() {
	usArr := []int{5, 2, 6, 3, 1, 4}
	sArr := bubbleSort(usArr)
	fmt.Println(sArr)
}