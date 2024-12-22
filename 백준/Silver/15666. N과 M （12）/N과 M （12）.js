const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [N, M] = input[0].split(" ").map(Number);
const splited = input[1].split(" ").map(Number);
const arr = [...new Set(splited).values()].sort((a, b) => a - b);

const result = new Map();

const getString = (lst, k) => {
  if (k === 0) {
    const tmp = lst.map((l) => arr[l]).sort((a, b) => a - b);
    result.set(tmp.join(","), tmp);
    return;
  }

  for (let i = 0; i < arr.length; i++) {
    getString([...lst, i], k - 1);
  }
};

const answer = () => {
  for (let i = 0; i < arr.length; i++) {
    getString([i], M - 1);
  }
  [...result.values()].forEach((v) => console.log(...v));
};

answer();