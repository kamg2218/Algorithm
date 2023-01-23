function solution(A, B) {
    if (A === B) return 0;
    for (let i = 1; i < A.length; i++) {
        if (A.slice(-i).concat(A.slice(0, A.length - i)) === B) {
            return i;
        }
    }
    return -1;
}