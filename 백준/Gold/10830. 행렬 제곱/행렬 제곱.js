const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const split = input.map((m) => m.split(" ").map(Number));

const [n, m] = split[0];

const matrix = (left, right) => {
  const result = Array.from(Array(n), () => Array.from(Array(n), () => 0));

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      for (let k = 0; k < n; k++) {
        result[i][j] = (result[i][j] + left[i][k] * right[k][j]) % 1000;
      }
    }
  }
  return result;
};

const getMatrix = (num) => {
  if (num === 1) return split.slice(1);

  let result = getMatrix(Math.floor(num / 2));
  result = matrix(result, result);
  if (num % 2) return matrix(result, split.slice(1));
  return result;
};

const solution = () => {
  const result = getMatrix(m);

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      result[i][j] %= 1000;
    }
    console.log(...result[i]);
  }
};

solution();