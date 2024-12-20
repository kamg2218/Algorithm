const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [N, M] = input[0].split(" ").map(Number);

const dict = new Map();

// dict 초기화
for (let i = 1; i <= N; i++) {
  dict.set(input[i], i);
}

const answer = () => {
  const idx = N + 1;
  for (let i = 0; i < M; i++) {
    const num = input[idx + i];
    if (isNaN(num)) console.log(dict.get(input[idx + i]));
    else console.log(input[num]);
  }
};

answer();