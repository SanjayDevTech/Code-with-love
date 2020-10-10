function largestOfFour(arr) {
  //create an empty array
  let newArr = [];
  for(let x = 0; x < arr.length; x++){
    //sort the array
    arr[x].sort((a,b) => a - b);
    // push the last index of the array to an empty array
    newArr.push(arr[x].pop());
  }
  // return the newArray
  return newArr;
}

largestOfFour([[4, 5, 1, 3], [13, 27, 18, 26], [32, 35, 37, 39], [1000, 1001, 857, 1]]);
