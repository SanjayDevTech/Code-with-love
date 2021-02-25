//arrow function

var add = (a, b)=> {
    return a+b;
}


// example of let

var a = 1;
{
    let a = 2;
    console.log(a); // it will log 2
}

console.log(a); // it will log 1 as here a = 1;


//
var x = 10;
// Here x is 10
{
  const x = 2;
  console.log(x);// Here x is 2
}
console.log(x);// Here x is 10


//default parameter

function defParamAdd (a,b = 0){
    return a+b;
}

console.log(defPraramAdd(5));  //will print 5
console.log(defPraramAdd(5,5));//will print 10


// find() method returns the value of the first array element that passes a test function.

var num = [1,10,3,4,4,5,6,7,4,4,8,9,10];
var first = num.find(myFunction) // it will return 10

function myFunction(value, index, array) {
    return value > 7;
}