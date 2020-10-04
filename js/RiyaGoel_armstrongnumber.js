// program to check an Armstrong number of three digits

let sum = 0;
let number = prompt('Enter a three-digit positive integer: ');

let temp = number;
while (number > 0) {
    
    let remainder = number % 10;

    sum += remainder * remainder * remainder;

    number = parseInt(number / 10); 
}
// check the condition
if (sum == temp) {
    console.log(`${number} is an Armstrong number`);
}
else {
    console.log(`${number} is not an Armstrong number.`);
}