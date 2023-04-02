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

function solution(number, limit, power) {  
    return new Array(number).fill(0).reduce((acc, _, idx) => {
        const cnt = getDivisorCnt(idx + 1);
        if (cnt > limit) return acc + power;
        return acc + cnt;
    }, 0);
}