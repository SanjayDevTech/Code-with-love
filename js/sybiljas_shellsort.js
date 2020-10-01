function shellsort(arr){
    let n =parseInt(arr.length/2)
    for(let i=0;i<arr.length;i++){
        while(n>=1){
            for(let j=0;j<arr.length;j++){
                if(arr[n+j]<=arr[j]){
                    let temp = arr[n+j]
                    arr[n+j] = arr[j]
                    arr[j]=temp
     
                }
                console.log(arr)
            }
            n = n-1
        }
    }
    return arr;     
}

// example run
//shellsort([42, 133, 7, 23,43,67, 74, 670, 49,32,39,49,23,49,16,12,123, 5,5,8,8,10,7.5,8.5]);