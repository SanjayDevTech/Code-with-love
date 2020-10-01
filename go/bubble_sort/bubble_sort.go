package main

import "fmt"

// BubbleSort - Sorts a list via bubble algorithm
func BubbleSort(list []int) {
	fmt.Println("Initial list:")
	fmt.Println(list)
	var aux int

	for i := 0; i < len(list); i++ {
		for j := 0; j < len(list)-1; j++ {
			if list[j] > list[j+1] {
				aux = list[j]
				list[j] = list[j+1]
				list[j+1] = aux
			}
		}
	}

	fmt.Println("Sorted list:")
	fmt.Println(list)

}

// Run this as go run go/bubble_sort/bubble_sort.go
func main() {
	list := []int{10, 5, 3, 9, 2, 8, 7, 1, 4, 6}
	BubbleSort(list)
}
