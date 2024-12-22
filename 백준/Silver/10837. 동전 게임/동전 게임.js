const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const K = Number(input[0]);
const C = Number(input[1]);
const arr = input.slice(2).map((r) => r.split(" ").map(Number));

const answer = () => {
  arr.forEach(([a, b]) => {
    if (a === b) console.log(1);
    else if (a > b && K + b - 2 * a + 3 > 0) console.log(1);
    else if (a < b && K + a - 2 * b + 2 > 0) console.log(1);
    else console.log(0);
  });
};

answer();