const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [N, M] = input[0].split(" ").map(Number);
const arr = input[1]
  .split(" ")
  .map(Number)
  .sort((a, b) => a - b);

const result = new Map();

const getString = (lst, k) => {
  if (k === 0) {
    const tmp = lst.map((l) => arr[l]);
    result.set(tmp.join(","), tmp);
    return;
  }

  for (let i = 0; i < N; i++) {
    if (!lst.includes(i)) getString([...lst, i], k - 1);
  }
};

const compareNumber = (a, b) => {
  for (let i = 0; i < M; i++) {
    if (a[i] === b[i]) continue;
    return a[i] - b[i];
  }
  return a[M - 1] - b[M - 1];
};

const answer = () => {
  for (let i = 0; i < N; i++) {
    getString([i], M - 1);
  }
  const r = [...result.values()];
  r.sort(compareNumber);
  r.forEach((v) => console.log(...v));
};

answer();