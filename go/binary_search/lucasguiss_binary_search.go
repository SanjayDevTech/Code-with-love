package main

import "fmt"

// BNode - Node for the tree where value is the current number, left and right are the tree sides
type BNode struct {
	Value int
	Left  *BNode
	Right *BNode
}

// Tree - The implementation of a binary search on a tree
func Tree(current *BNode, value int) bool {
	if current == nil {
		return false
	}

	if current.Value == value {
		return true
	} else if current.Value > value {
		return Tree(current.Left, value)
	}

	return Tree(current.Right, value)
}

// List - Binary search through a list
func List(list []int, value int) int {
	var start = 0
	var end int = len(list) - 1

	for start <= end {
		mid := end + start/2
		if list[mid] == value {
			fmt.Println("Found value!")
			return 0
		} else if list[mid] < value {
			start = mid + 1
		} else {
			end = mid - 1
		}
	}

	fmt.Println("Not found!")
	return 0
}

// Run this as go run go/binary_search/lucasguiss_binary_search.go
func main() {
	list := []int{93, 42, 34, 64, 26, 67, 23, 1, 4, 60}
	var value int
	fmt.Println("Insert a value: ")
	fmt.Scanf("%d", &value)
	List(list, value)
}
