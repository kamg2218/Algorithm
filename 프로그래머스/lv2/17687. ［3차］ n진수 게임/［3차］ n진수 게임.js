function solution(n, t, m, p) {
    var answer = '';
    let result = '';
    let num = 0;
    while (result.length <= m * t + p - 1) {
        result += num.toString(n).toUpperCase();
        num += 1;
    }
    for (let i = 0; i < t; i++) {
        answer += result[m * i + p - 1];
    }
    return answer;
}