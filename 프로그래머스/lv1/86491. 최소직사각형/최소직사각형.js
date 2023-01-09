function solution(sizes) {
    const answer = [0, 0];
    const result = sizes.map(size => [Math.min(size[0], size[1]), Math.max(size[0], size[1])]);
    
    result.forEach(([a, b]) => {
        if (a > answer[0]) {
            answer[0] = a;
        }
        if (b > answer[1]) {
            answer[1] = b;
        }
    });
    return answer[0] * answer[1];
}