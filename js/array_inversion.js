function number_of_InversionsNaive(arr) {
    var ctr = 0;
    for (var i = 0; i < arr.length; i++) {
        for (var j = i + 1; j < arr.length; j++) {
            if (arr[i] > arr[j]) 
              ctr++;
        }
    }
    return ctr;
}

console.log(number_of_InversionsNaive([0, 3, 2, 5, 9]));   
console.log(number_of_InversionsNaive([1, 5, 4, 3]));   
console.log(number_of_InversionsNaive([10, 30, 20, -10]));