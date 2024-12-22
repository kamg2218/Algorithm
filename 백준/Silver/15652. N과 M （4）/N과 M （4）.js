const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [N, M] = input[0].split(" ").map(Number);

const getString = (lst, k) => {
  if (k === 0) {
    console.log(...lst);
    return;
  }

  for (let i = lst.at(-1); i <= N; i++) {
    getString([...lst, i], k - 1);
  }
};

const answer = () => {
  for (let i = 1; i <= N; i++) {
    getString([i], M - 1);
  }
};

answer();