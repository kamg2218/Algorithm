function solution(word) {
    var answer = 0;
    const rule = [781, 156, 31, 6, 1];
    const alpha = {
        'A': 0,
        'E': 1,
        'I': 2,
        'O': 3,
        'U': 4,
    };
    
    word.split('').forEach((w, idx) => {
        answer += rule[idx] * alpha[w];
    })
    return answer + word.length;
}