const isAnagram = (stringA, stringB) => {
  // helper function to give word counts
  const giveMap = (str) => {
    let wordCount = {};
    for (let letter of str) {
      if (wordCount.hasOwnProperty(letter)) {
        wordCount[letter]++;
      } else {
        wordCount[letter] = 1;
      }
    }
    return wordCount;
  };
  // if the lengths of the strings are not the same then clearly they can't be anagrams
  if (stringA.length != stringB.length) return false;
  const countA = giveMap(stringA);
  const countB = giveMap(stringB);

  // checking count of each letter in the strings is same
  for (let letter in countA) {
    if (countA[letter] !== countB[letter]) {
      return false;
    }
  }
  return true;
};

const stringA = "abcd";
const stringB = "cbda";
const answer = isAnagram(stringA, stringB);
console.log(` Is ${stringA} anagram of ${stringB} : ${answer}`);
