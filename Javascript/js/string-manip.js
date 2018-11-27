
// Reverse a string.
//
// Given an input string (s), return a string with all characters of s
// in the reverse the order of the original.
//
// Eg. "Foo bar!" -> "!rab ooF"

const str_reverse = str => {
  return str.split("").reverse().join("");
}

// Convert a comma-separated values (CSV) string to a 2D array.

const csv_to_array = (data, delimiter = ',', omitFirstRow = false) =>
  data.slice(omitFirstRow ? data.indexOf('\n') + 1 : 0)
    .split('\n')
    .map(arr => arr.split(delimiter));

// TEST
console.log(csv_to_array('a,b\nc,d')); 
console.log(csv_to_array('a;b\nc;d', ';')); 
console.log(csv_to_array('head1,head2\na,b\nc,d', ',', true));
