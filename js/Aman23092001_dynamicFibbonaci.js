function fib(n){
    var bottom_up_arr = [0, 1];
    for(var i = 0; i <= n-2; i++){
        bottom_up_arr.push(bottom_up_arr[i] + bottom_up_arr[i+1]);
    }
    return bottom_up_arr[n];
}

console.log(fib(75));