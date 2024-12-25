const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const split = input.map((m) => m.split(" ").map(BigInt));

const n = 2;
const m = BigInt(split[0][0]);

const div = BigInt(1000000007);

const unit = [
  [1, 1],
  [1, 0],
];

const matrix = (left, right) => {
  const result = Array.from(Array(n), () =>
    Array.from(Array(n), () => BigInt(0))
  );

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      for (let k = 0; k < n; k++) {
        result[i][j] += (BigInt(left[i][k]) * BigInt(right[k][j])) % div;
      }
      result[i][j] %= div;
    }
  }
  return result;
};

const getMatrix = (num) => {
  if (num === BigInt(1)) return unit;

  let result = getMatrix(num / BigInt(2));
  result = matrix(result, result);
  return num % BigInt(2) ? matrix(result, unit) : result;
};

const solution = () => {
  if (m < 1) return console.log(0);
  const result = getMatrix(m);
  console.log(Number(BigInt(result[1][0]) % div));
};

solution();