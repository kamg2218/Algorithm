function solution(r1, r2) {
    var answer = 0;
    
    for (let i = 1; i <= r2; i++) {
        const last = parseInt(Math.sqrt(r2*r2 - i*i));
        let start = Math.ceil(Math.sqrt(r1*r1 - i*i));
        start = isNaN(start) ? 0 : start;
        answer += last - start + 1;
    }
    return answer * 4;
} 