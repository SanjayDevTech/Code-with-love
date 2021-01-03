//function to swap elements
function swap(a, first_Index, second_Index) {
  var temp = a[first_Index];
  a[first_Index] = a[second_Index];
  a[second_Index] = temp;
}

//function for bubble sort
function bubbleSort(a) {
  var l = a.length;
    i,
    j,
    stop;

  for (i = 0; i < l; i++) {
    for (j = 0, stop = l - i; j < stop; j++) {
      if (a[j] > a[j + 1]) {
        swap(a, j, j + 1);
      }
    }
  }
  return a;
}

var a = [3, 2, 4, 1, 5];
console.log(bubbleSort(a));
