//function to swap elements
function swap(arr, first_Index, second_Index) {
  var temp = arr[first_Index];
  arr[first_Index] = arr[second_Index];
  arr[second_Index] = temp;
}

//function for bubble sort
function bubbleSort(arr) {
  var len = arr.length,
    i,
    j,
    stop;

  for (i = 0; i < len; i++) {
    for (j = 0, stop = len - i; j < stop; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr, j, j + 1);
      }
    }
  }
  return arr;
}

var arr = [3, 2, 4, 1, 5];
console.log(bubbleSort(arr));
