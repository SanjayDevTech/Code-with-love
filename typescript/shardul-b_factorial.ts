const factorial:any =(num:number)=>{
    if (num === 1) {
        return num;
    }else{
        return num*factorial(num-1)
    }
}
let num:any = 5;
let fact:any=factorial(num)
console.log(`Factorial of ${num} = ${fact}`);