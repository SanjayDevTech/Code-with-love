const reverseString = (str) => {
  let ans = "";
  for (let letter of str) {
    ans = letter + ans;
  }
  return ans;
};

const stringA = "ABCD";
const ans = reverseString(stringA);

console.log(`${stringA} when reversed is ${ans}`);
