var factorial = function (num) {
    if (num === 1) {
        return num;
    }
    else {
        return num * factorial(num - 1);
    }
};
var num = 5;
var fact = factorial(num);
console.log("Factorial of " + num + " = " + fact);
