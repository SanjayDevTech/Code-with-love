const checkPalindrome = (str) => {
  const len = str.length;
  for (let i = 0; i < len / 2; i++) {
    if (str[i] !== str[len - 1 - i]) {
      return false;
    }
  }
  return true;
};

const stringA = "ABCBA";
const ans = checkPalindrome(stringA);
console.log(`Is ${stringA} a palindrome : ${ans}`);
