package main

import "fmt"

var Array [15]int = [15]int{15,14,13,10,11,12,1,3,4,2,5,6,7,8,9}

func bubbleSort(arr [15]int){
	n:= 15

	swapped := true

	for swapped {
		swapped = false
		for i:= 1; i < n ; i++ {
			if arr[i-1] > arr[i] {
                arr[i], arr[i-1] = arr[i-1], arr[i]
                swapped = true
            }
        }
	}
	
	fmt.Println(arr)
}


func main() {
	fmt.Println("Bubble Sort")
	fmt.Println(Array)
	fmt.Println("Sorting.......")
	bubbleSort(Array)
}