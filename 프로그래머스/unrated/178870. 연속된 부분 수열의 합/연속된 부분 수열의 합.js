function solution(sequence, k) {
    const answer = [];
    
    let start = 0;
    let end = 0;
    let sum = sequence[0];
    while (start <= end && end < sequence.length) {
        if (sum === k) answer.push([start, end]);
        if (sum >= k) {
            sum -= sequence[start];
            start += 1;
        } else {
            end += 1;
            sum += sequence[end];
        }
    }
    
    answer.sort(([a, b], [c, d]) => (b - a) - (d- c));
    return answer[0];
}