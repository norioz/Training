// Convert a number into the spoken English version of that number.
const digitWords = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
  "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
  "nineteen"];
const tensWords = ["", "", "twenty", "thrity", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"]
const dToS = digit => {
  if (digit < 0 || digit > 19) {
    throw "Digit " + digit + "not in range.";
  }
  return digitWords[digit];
}

const speakNum = num => {
  if (num < 20) {
    return digitWords[num];
  }
  else if (num < 100) {
    let dividend = Math.floor(num / 10);
    let remainder = num % 10;
    return tensWords[dividend] + (remainder === 0 ? "" : " " + speakNum(remainder));
  }
  else if (num < 1000) {
    let dividend = Math.floor(num / 100);
    let remainder = num % 100;
    return speakNum(dividend) + " hundred" + (remainder === 0 ? "" : " and " + speakNum(remainder));
  }
  else if (num < 1000000) {
    let dividend = Math.floor(num / 1000);
    let remainder = num % 1000;
    return speakNum(dividend) + " thousand" + (remainder === 0 ? "" : " " + speakNum(remainder));
  }
  else {
    return "Not there, yet."
  }
}

// TEST
console.log(speakNum(0));
console.log(speakNum(19));
console.log(speakNum(20));
console.log(speakNum(39));
console.log(speakNum(99));
console.log(speakNum(100));
console.log(speakNum(101));
console.log(speakNum(130));
console.log(speakNum(999));
console.log(speakNum(1000));
console.log(speakNum(123456));
console.log(speakNum(200000));
console.log(speakNum(999999))
console.log(speakNum(1000000));

// Convert a number to an array of digits.
const digitize = num => {
  return num.toString().split("").map(i => parseInt(i));
}

// TEST
console.log(digitize(123));  // [1,2,3]
console.log(digitize(1230)); // [1,2,3,0]


// Filter out the specified values from an specified array.

const pull = (arr, ...args) => {
  let filterred = arr.filter(e => !args.includes(e));
  arr.length = 0;  // empty the array
  filterred.forEach(elt => arr.push(elt));
  return arr;
}

// TEST
let arra1 = ['a', 'b', 'c', 'a', 'b', 'c'];
console.log(pull(arra1, 'a', 'c')); // ["b", "b"]
let arra2 =  ['a', 'b', 'c', 'a', 'b', 'c'];
console.log(pull(arra2, 'b')); // ["a", "c", "a", "c"]
