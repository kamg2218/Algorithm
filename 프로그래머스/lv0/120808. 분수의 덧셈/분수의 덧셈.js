function solution(numer1, denom1, numer2, denom2) {
    var answer = [
        numer1 * denom2 + numer2 * denom1,
        denom1 * denom2
    ];
    
    for (let i = Math.floor(Math.sqrt(answer[1])); i >= 2; i--) {
        if (!(answer[0] % i) && !(answer[1] % i)) {
            answer[0] /= i;
            answer[1] /= i;
        }
    }
    return answer;
}