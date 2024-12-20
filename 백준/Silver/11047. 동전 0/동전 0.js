const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [N, K] = input[0].split(" ").map(Number);
const coins = input.map(Number);

let num = K;
let cnt = 0;

const answer = () => {
  for (let i = N; i >= 1; i--) {
    if (num <= 0) break;

    if (coins[i] <= num) {
      const quote = parseInt(num / coins[i]);
      num -= coins[i] * quote;
      cnt += quote;
    }
  }
  console.log(cnt);
};

answer();