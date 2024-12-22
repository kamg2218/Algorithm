const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const answer = () => {
  const idx = Number(input[1]);
  console.log(input[0][idx - 1]);
};

answer();