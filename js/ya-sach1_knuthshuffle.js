const shuffle = (array) => {
  let currentIndex = array.length;
  let randomIndex;
  let temp;

  // It runs as long as there are elements to shuffle
  while (0 !== currentIndex) {
    // Pick an element
    randomIndex = Math.floor(Math.random() * currentIndex);
    currentIndex -= 1;

    // Swap it with the current elemen5
    temp = array[currentIndex];
    array[currentIndex] = array[randomIndex];
    array[randomIndex] = temp;
  }

  return array;
};

const arr = [2, 11, 37, 42];
console.log(shuffle(arr));
