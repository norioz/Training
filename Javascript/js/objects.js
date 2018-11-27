
// Compare two objects to determine if the first (a),
// contains equivalent property values to the second one (b).

const compareObjs = (a, b) => {
  return Object.keys(b).every((key) => {
    return a.hasOwnProperty(key) && a[key] === b[key];
  });
}

// TEST
console.log(compareObjs({"n": "a", "x": 1}, {"n": "a", "x": 1}));
console.log(compareObjs({"n": "a", "x": 2}, {"n": "a", "x": 1}));
const a = {"name": "foo"};
const b = {"nam": "foo"};
const c = {"name": "foo"};
console.log(compareObjs(a, b));
console.log(compareObjs(a, c));
