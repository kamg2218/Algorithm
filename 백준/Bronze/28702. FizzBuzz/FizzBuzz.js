const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const getString = (str) => {
  if (!(str % 3) && !(str % 5)) return "FizzBuzz";
  else if (!(str % 3)) return "Fizz";
  else if (!(str % 5)) return "Buzz";
  return str;
};

const answer = () => {
  let idx = input.map((i) => !isNaN(i)).findIndex((i) => i);
  const num = Number(input[idx]) + 3 - idx;
  console.log(getString(num));
};

answer();