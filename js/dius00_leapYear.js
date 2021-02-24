// A year is a Leap Year

// on every year that is evenly divisible by 4
// except every year that is evenly divisible by 100
// unless the year is also evenly divisible by 400


function isLeap (num) {
  // if a number ends with X00 it is divible by 100
  if(num.toString().substring(2,) == '00'){ 
    // if a number is divisible by 100 and 400 it is a leap year and return true
    if(num % 400 == 0) return true;
    // if a number is divisible by 100 and not by 400 it is not a leap year and return false
    else return false;
  }
  // if a number is not divisible by 100
  else{
    // if it is divisible by 4 it is a leap year and return false
    if(num%4 == 0) return true;
    // if it is not divisible by 4 it is not a leap year
    else return false;
  }
};

// examples

console.log(isLeap(2100)) // ==> false

console.log(isLeap(2000)) // ==> true

console.log(isLeap(2020)) // ==> true

console.log(isLeap(1975)) // ==> false

console.log(isLeap(312))  // ==> true
