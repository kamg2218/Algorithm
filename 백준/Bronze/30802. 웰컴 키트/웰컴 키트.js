const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const N = Number(input[0]);
const size = input[1].split(" ").map(Number);
const [T, P] = input[2].split(" ").map(Number);

const answer = () => {
  let cnt = 0;
  size.forEach((s) => {
    cnt += Math.floor(s / T);
    if (s % T) cnt++;
  });
  console.log(cnt);
  console.log(Math.floor(N / P), N % P);
};

answer();