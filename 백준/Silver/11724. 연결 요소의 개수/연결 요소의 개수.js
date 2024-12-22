const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [N, M] = input[0].split(" ").map(Number);
const arr = input.slice(1).map((r) => r.split(" ").map(Number));

const map = new Map(Array.from(Array(N), (_, i) => [i + 1, i + 1]));

const updateMap = (prev, next) => {
  map.forEach((m, n) => {
    if (m === prev) map.set(n, next);
  });
};

const answer = () => {
  for (let i = 0; i < M; i++) {
    const [a, b] = arr[i];
    if (map.has(a) && map.has(b)) {
      if (map.get(a) !== map.get(b)) updateMap(map.get(b), map.get(a));
    } else if (map.has(a)) {
      map.set(b, map.get(a));
    } else if (map.has(b)) {
      map.set(a, map.get(b));
    }
  }
  console.log(new Set(map.values()).size);
};

answer();