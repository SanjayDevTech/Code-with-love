const countingSort = (arr) => {
  // helper function to give count of elements
  const giveMap = (arr) => {
    let countMap = {};
    for (let num of arr) {
      if (countMap.hasOwnProperty(num)) {
        countMap[num]++;
      } else {
        countMap[num] = 1;
      }
    }
    return countMap;
  };

  const countMap = giveMap(arr);
  const sortedArr = [];
  for (key in countMap) {
    for (i = 0; i < countMap[key]; i++) {
      sortedArr.push(key);
    }
  }
  return sortedArr;
};

const arr = [4, 6, 7, 2, 2, 3];
const sortedArr = countingSort(arr);
console.log(`Original Array : ${arr} \n Sorted Array : ${sortedArr}`);
