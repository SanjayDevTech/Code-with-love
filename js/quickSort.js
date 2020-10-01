var sortArray = function(array, start, end) {
    //start and end index of the array will be defined by subsequent calls
    //on the first call, they will be the start and end of the entire array
    start = start || 0;
    end = end || array.length-1
   
    //as long as we have an array of at least size 2
     while (start < end) {
       let pivotFinalPosition = partition(array, start, end);
       
        // If left part is smaller, then recur for left 
        // part and handle right part iteratively 
       if (pivotFinalPosition - start < end - pivotFinalPosition) { 
           sortArray(array, start, pivotFinalPosition - 1); 
           start = pivotFinalPosition + 1; 
       } 
  
       // Else recur for right part 
       else{ 
           sortArray(array, pivotFinalPosition + 1, end); 
           end = pivotFinalPosition - 1; 
       } 
  
     }
    return array
  };
  
  const partition = function(array, start, end) {
    //i keeps track of the last position that a small element was placed in
    //by default, we want to begin at start-1 because we always increment before swapping
    let i = start-1;
  
    //You can choose anything for the pivot. I chose the last element
    let pivot = array[end];
    //j is going to be our "scanner". It is going to look ahead for things to swap
    //for every element except the last one (pivot)
    for (let j = start; j < end; j++) {
      //if the "scanned" element is less than the pivot
      if (array[j] <= pivot) {
        //move i one space forward before swapping
        i++
        //swap the element at j with the element at i
        //Es6 swap shorthand;
        [array[i], array[j]] = [array[j], array[i]]
      }
    }
    //finally before we are done, we want to move i forward one last time and swamp that element with the pivot
    i++
    [array[i], array[end] ] = [array[end], array[i]]
    //return the final position of the pivot
    return i;
  }