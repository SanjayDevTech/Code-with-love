// linear search function
function linearSearch(arr, item) {
  for (var i = 0; i < arr.length; i++) {
    if (arr[i] === item) {
      return i;
    }
  }
  return null;
}

var arr = [5, 4, 3, 2, 1];
var item = 3;
var status = linearSearch(arr, item);
if (status === null) {
  console.log("Element not present in the array");
} else {
  console.log("Element present in the array");
}
