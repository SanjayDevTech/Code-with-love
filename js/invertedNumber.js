function invertido(num, inv = 0){
    if(num > 0)
        return invertido((num / 10 | 0), num % 10 + inv * 10);
    else
        return inv;
}

//Examples 

console.log(invertido(18));
console.log(invertido(156));
console.log(invertido(2506));
console.log(invertido(41563));