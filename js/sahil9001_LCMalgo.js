//GCD function required to calculate LCM
let euclideanAlgorithm = function (A, B) {
    // Make input numbers positive.
    const a = Math.abs(A);
    const b = Math.abs(B);

    // To make algorithm work faster instead of subtracting one number from the other
    // we may use modulo operation.
    return (b === 0) ? a : euclideanAlgorithm(b, a % b);
}

//LCM function implementation
let LCMfunc = function (a, b) {
    return ((a === 0) || (b === 0)) ? 0 : Math.abs(a * b) / euclideanAlgorithm(a, b);
}