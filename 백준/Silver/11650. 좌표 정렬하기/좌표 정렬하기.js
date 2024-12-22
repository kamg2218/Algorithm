const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const N = Number(input[0]);
const arr = input.map((r) => r.split(" ").map(Number)).slice(1);
arr.sort(([a, b], [c, d]) => (a === c ? b - d : a - c));
arr.forEach(([a, b]) => console.log(a, b));