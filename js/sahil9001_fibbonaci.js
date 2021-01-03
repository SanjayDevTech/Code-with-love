let fibbonaci = function (n) {
    //Creates an array with first fibbonaci element
    const fib = [1];
    let currentValue = 1, previousValue = 0;
    if (n == 1) {
        return fib;
    }
    let iterationsCounter = n - 1;

    while (iterationsCounter) {
        //Adding previous value
        currentValue += previousValue;
        previousValue = currentValue - previousValue;
        //Appending to the sequence
        fib.push(currentValue);
        //decrementing iterator variable
        iterationsCounter -= 1;
    }
    //Returning the fib sequence as an array
    return fib;
}

let n = 10;
console.log(fibbonaci(n));