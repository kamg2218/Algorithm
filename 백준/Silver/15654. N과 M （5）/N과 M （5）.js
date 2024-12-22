const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [N, M] = input[0].split(" ").map(Number);
const arr = input[1]
  .split(" ")
  .map(Number)
  .sort((a, b) => a - b);

const getString = (lst, k) => {
  if (k === 0) {
    console.log(...lst);
    return;
  }

  for (let i = 0; i < N; i++) {
    if (!lst.includes(arr[i])) getString([...lst, arr[i]], k - 1);
  }
};

const answer = () => {
  for (let i = 0; i < N; i++) {
    getString([arr[i]], M - 1);
  }
};

answer();