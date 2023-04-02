function solution(n, s) {
    if (n === 1) return [s];
    if (s === 1 || n > s) return [-1];
    
    const quote = parseInt(s / n);
    const rest = s % n
    return new Array(n).fill(quote).fill(quote + 1, n - rest, n);
}