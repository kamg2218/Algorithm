const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [N, M] = input[0].split(" ").map(Number);

const dict = new Map();
const result = [];

// dict 초기화
for (let i = 1; i <= N; i++) {
  dict.set(input[i], i);
}

const answer = () => {
  const idx = N + 1;
  for (let i = 0; i < M; i++) {
    if (dict.has(input[idx + i])) result.push(input[idx + i]);
  }

  console.log(result.length);
  result.sort((a, b) => a.localeCompare(b));
  result.forEach((r) => console.log(r));
};

answer();