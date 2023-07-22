function solution(n, k) {
    var answer = [];
    const result = Array(n).fill(0).map((_, idx) => idx + 1);
    
    const getFactorial = (num) => {
        if (num <= 1) return 1;
        else if (num === 2) return 2;
        return num * getFactorial(num - 1);
    }
    
    k -= 1;
    for (let i = n - 1; i > -1; i--) {
        const factorial = getFactorial(i);
        if (k >= factorial) {
            const quote = Math.floor(k / factorial);
            answer.push(result[quote]);
            result.splice(quote, 1);
            k -= quote * factorial;
        } else {
            answer.push(result[0]);
            result.shift();
        }
    }
    return answer.concat(result);
}