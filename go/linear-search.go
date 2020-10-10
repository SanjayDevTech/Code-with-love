// Run with: go run linear-search.go
//
// Implementation of linear search algorithm:
// Starts at the front of the list and checks each item to see if it is the
// target item. If so, return the index. If the target item is not in the list,
// return -1
package main

import "fmt"

func linear_search(arr []int, target int) int {
    // arr: an array of integers
    // target: the value to search for in the array

    for i := 0; i < len(arr); i++ {
	if arr[i] == target {
	    return i
	}
    }

    return -1
}

func main() {
    // test with an int array with 5 items
    var arr1 = []int {10, 20, 30, 40, 50}
    var target int = 30
    var result int

    result = linear_search(arr1, target)
    if result != 2 {
	fmt.Println("Error: expected 2, got", result)
    }

    // test with an array of 10 elements
    var arr2 = []int {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}
    target = 9000

    result = linear_search(arr2, target)
    if result != -1 {
	fmt.Println("Error: expected -1, got", result)
    }
}
