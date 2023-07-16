function solution(k, d) {
    let answer = 0;
    for (let i = 0; i <= d; i += k) {
        answer += Math.floor(Math.sqrt(d * d - i * i) / k) + 1;
    }
    return answer;
}