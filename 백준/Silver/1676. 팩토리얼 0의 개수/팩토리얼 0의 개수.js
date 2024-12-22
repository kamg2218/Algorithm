const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const num = Number(input[0]);

const getCount = (n, q) => {
  let cnt = 0;
  while (n > 1) {
    if (n % q) {
      break;
    }
    cnt++;
    n = parseInt(n / q);
  }
  return cnt;
};

const answer = () => {
  let cnt = [0, 0];
  for (let i = num; i > 1; i--) {
    cnt[0] += getCount(i, 2);
    cnt[1] += getCount(i, 5);
  }
  console.log(Math.min(cnt[0], cnt[1]));
};

answer();