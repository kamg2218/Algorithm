function solution(number, limit, power) {
    var answer = 0;
    
    const getDivisorCnt = (num) => {
        let cnt = 0;
        const last = Math.sqrt(num);
        
        if (num === 1) return 1;
        for (let i = 1; i <= last; i++) {
            if (num % i === 0) cnt += 2;
            if (i === last) cnt -= 1;
        }
        return cnt;
    }
    
    for (let i = 1; i <= number; i++) {
        let cnt = getDivisorCnt(i);
        if (cnt > limit) {
            cnt = power;
        }
        answer += cnt;
    }
    return answer;
}