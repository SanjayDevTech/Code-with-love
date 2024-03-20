const factorial = (n) => {
  let ans = 1;
  while (n > 1) {
    ans *= n;
    n--;
  }
  return ans;
};

const num = 5;
ans = factorial(num);
console.log(`Factorial of ${num} is ${ans}`);
