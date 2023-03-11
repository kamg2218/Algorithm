function solution(n, m, section) {
    let answer = 0;
    let last = 0;
    
    if (m === 1) return section.length;
    section.forEach(value => {
        if (last < value) {
            last = value + m - 1;
            answer++;
        }
    });
    return answer;
}