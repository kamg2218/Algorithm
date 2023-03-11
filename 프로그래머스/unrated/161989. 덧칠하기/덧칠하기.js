function solution(n, m, section) {
    var answer = 0;
    let start = -1;
    
    if (m === 1) return section.length;
    for (let i = 0; i < section.length; i++) {
        if (start === -1 || section[i] >= start + m) {
            start = section[i];
            answer++;
        }
    }
    return answer;
}