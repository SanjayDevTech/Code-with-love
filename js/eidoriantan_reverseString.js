
/**
 *  Reverses string
 */
function reverse (string) {
  if (typeof string !== 'string') {
    throw new TypeError('String is not type of string')
  }

  return string.split('').reverse().join('')
}

// Simple usage
const reversed = reverse('Hello, World!')

// !dlroW ,olleH
console.log(reversed)
