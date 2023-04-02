function solution(n, s) {
    var answer = [];
    
    if (n === 1) return [s];
    if (s === 1 || n > s) return [-1];
    const num = parseInt(s / n);
    for (let i = 0; i < n; i++) {
        answer.push(num);
    }
    let rest = s % n;
    let idx = n - 1;
    while (rest) {
        answer[idx] += 1;
        idx--;
        rest--;
    }
    return answer;
}
