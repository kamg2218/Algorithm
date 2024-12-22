const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [N, M] = input[0].split(" ").map(Number);
const splited = input.map((i) => i.split(" "));
const dict = new Map(splited.slice(1, N + 1));

const answer = () => {
  for (let i = 1; i <= M; i++) {
    console.log(dict.get(input[N + i]));
  }
};

answer();