function solution(s) {
    var answer = [0, 0];
    
    while (s !== '1') {
        const result = s.split('').filter(i => i === '1').length;
        answer[0] += 1;
        answer[1] += s.length - result;
        s = result.toString(2);
    }
    return answer;
}