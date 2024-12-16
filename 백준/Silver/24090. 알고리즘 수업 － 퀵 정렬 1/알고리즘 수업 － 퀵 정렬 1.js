const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const arr = input.map((i) => i.split(" ").map(Number));

const len = arr[0][0];
const idx = arr[0][1];

let cnt = 0;
let result;

const swap = (a, b) => {
  let tmp = arr[1][a];
  arr[1][a] = arr[1][b];
  arr[1][b] = tmp;
  cnt++;
  if (cnt === idx) {
    result = [arr[1][a], arr[1][b]].sort((x, y) => x - y);
  }
};

const partition = (first, last) => {
  const value = arr[1][last];
  let i = first - 1;
  for (let j = first; j < last; j++) {
    if (arr[1][j] <= value) {
      swap(++i, j);
    }
  }
  if (i + 1 !== last) {
    swap(i + 1, last);
  }
  return i + 1;
};

const quickSort = (first, last) => {
  if (first >= last) return;

  const pivot = partition(first, last);
  quickSort(first, pivot - 1);
  quickSort(pivot + 1, last);
};

const solution = () => {
  quickSort(0, len - 1);
  if (cnt < idx) console.log(-1);
  else console.log(result[0], result[1]);
};

solution();
