const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [A, B, C] = input.map(Number);

const answer = () => {
  console.log(A + B - C);
  console.log(Number(input[0] + input[1]) - C);
};

answer();