function solution(n, k) {
    var answer = [];
    const result = Array(n).fill(0).map((_, idx) => idx + 1);
    let factorial = result.reduce((acc, cur) => acc * cur, 1);
    let num = n;
    
    while (answer.length < n) {
        factorial /= num--;
        const tmp = result.splice(Math.floor((k - 1) / factorial), 1);
        answer.push(...tmp);
        k %= factorial;
    }
    return answer;
//     const getFactorial = (num) => {
//         if (num <= 1) return 1;
//         else if (num === 2) return 2;
//         return num * getFactorial(num - 1);
//     }
    
//     k -= 1;
//     for (let i = n - 1; i > -1; i--) {
//         const factorial = getFactorial(i);
//         if (k >= factorial) {
//             const quote = Math.floor(k / factorial);
//             answer.push(result[quote]);
//             result.splice(quote, 1);
//             k -= quote * factorial;
//         } else {
//             answer.push(result[0]);
//             result.shift();
//         }
//     }
//     return answer.concat(result);
}

