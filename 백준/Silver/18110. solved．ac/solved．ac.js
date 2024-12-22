const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const N = Number(input[0]);
const arr = input
  .map(Number)
  .slice(1)
  .sort((a, b) => a - b);

const answer = () => {
  if (N === 0) {
    console.log(0);
    return;
  }
  const cnt = Math.round(N * 0.15);
  let sum = 0;
  for (let i = cnt; i < N - cnt; i++) {
    sum += arr[i];
  }
  console.log(Math.round(sum / (N - cnt * 2)));
};

answer();