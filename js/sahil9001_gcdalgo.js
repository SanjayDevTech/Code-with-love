let euclideanAlgorithm = function (A, B) {
    // Make input numbers positive.
    const a = Math.abs(A);
    const b = Math.abs(B);

    // To make algorithm work faster instead of subtracting one number from the other
    // we may use modulo operation.
    return (b === 0) ? a : euclideanAlgorithm(b, a % b);
}


//Taking two numbers
let a = 20, b = 10;
console.log("GCD of " + a + " " + b + " is " + euclideanAlgorithm(a, b));