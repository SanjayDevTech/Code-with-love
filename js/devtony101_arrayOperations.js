Array.prototype.union = function (arr) {
  // Returns the union between this array and arr
  return [...this, ...arr];
}

Array.prototype.interOperate = function (arr, f) {
  // Filter out the values of the array given a function f
  return this.filter(el => f(arr, el))
}

Array.prototype.intersection = function (arr) {
  // Returns a new array with the result of the intersection
  // between this array and arr
  return this.interOperate(arr, (arr, el) => arr.includes(el));
}

Array.prototype.difference = function (arr, symetric = false) {
  // Returns a new array with the result of the difference 
  // between this array and arr according to set operations
  const f = (arr, el) => !arr.includes(el);
  if (symetric) {
    let intersection = this.intersection(arr);
    return this.union(arr).interOperate(intersection, f);
  } else {
    return this.interOperate(arr, f);
  }
}

Array.prototype.padStart = function (element, n) {
  // Returns a new array with the specified element repeated n times
  // at the start
  return [...Array(n).fill(element), ...this];
}

Array.prototype.padEnd = function (element, n) {
  // Returns a new array with the specified element repeated n times
  // at the end
  return [...this, ...Array(n).fill(element)]
}

Array.prototype.purge = function (strict = false) {
  // Returns a new array with all the undefined and null values filtered out
  // If strict is true then ALL the falsy values will be removed as well
  return [...this].filter(el => {
    if (strict) {
      return el;
    } else {
      return typeof el !== "undefined" && String(el) !== "null";
    }
  });
}