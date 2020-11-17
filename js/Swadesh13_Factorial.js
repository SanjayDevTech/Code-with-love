// Factorial recursive
const fact_r = num => {
    return num < 2 ? 1 : num * fact_r(num - 1);
  };
// Factorial loop
const fact_l = num => {
    p = 1;
    for(i = 2; i<=num; i++){
        p*=i;
    }
    return p;
}

let n = 10;

console.log(fact_r(n))
console.log(fact_l(n))