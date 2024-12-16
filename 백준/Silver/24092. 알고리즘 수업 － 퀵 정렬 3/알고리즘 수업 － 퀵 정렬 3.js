const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const arr = input.map((i) => i.split(" ").map(Number));

const len = arr[0][0];
let finish = false;

const compare = () => {
  for (let i = 0; i <= len / 2; i++) {
    if (arr[1][i] !== arr[2][i]) return false;
    if (arr[1][len - i] !== arr[2][len - i]) return false;
  }
  return true;
};

const swap = (a, b) => {
  let tmp = arr[1][a];
  arr[1][a] = arr[1][b];
  arr[1][b] = tmp;
};

const partition = (first, last) => {
  const value = arr[1][last];
  let i = first - 1;
  for (let j = first; j < last; j++) {
    if (arr[1][j] <= value) {
      swap(++i, j);
      if (arr[1][i] === arr[2][i] && arr[1][j] === arr[2][j]) {
        if (compare()) return -1;
      }
    }
  }
  if (i + 1 !== last) {
    swap(i + 1, last);
    if (arr[1][i + 1] === arr[2][i + 1] && arr[1][last] === arr[2][last]) {
      if (compare()) return -1;
    }
  }
  return i + 1;
};

const quickSort = (first, last) => {
  if (first >= last) return;

  const pivot = partition(first, last);
  if (pivot === -1) {
    finish = true;
    return;
  }
  quickSort(first, pivot - 1);
  quickSort(pivot + 1, last);
};

const solution = () => {
  if (compare()) {
    console.log(1);
    return;
  }
  quickSort(0, len - 1);
  console.log(finish ? 1 : 0);
};

solution();
