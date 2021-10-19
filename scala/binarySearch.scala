object BinarySearch {
	def search(input: List[Int], value: Int): Int = {
		var start = 0
		var end = input.length - 1

		while (start <= end) {
			val mid = (start + end) / 2

			if (input(mid) == value) return mid

			if (input(mid) > value) end = mid - 1
			else start = mid + 1
		}
		-1
	}

	def test: Boolean = {
		// assumes input list is sorted, shouldn't handle malformed lists
		if (search(List(), 4) != -1) return false
		if (search(List(1, 2, 3), 4) != -1) return false
		if (search(List(1, 3, 5, 8, 9), 4) != -1) return false

		if (search(List(1, 3, 5, 8, 9), 1) != 0) return false
		if (search(List(1, 3, 5, 8, 9), 9) != 4) return false
		if (search(List(1, 3, 5, 8, 9), 5) != 2) return false
		if (search(List(1, 10, 100, 1000, 10000, 100000, 1000000), 100000) != 5) return false
		true
	}
}