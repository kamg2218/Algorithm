function solution(k, n, reqs) {
    var answer = -1;
    
    const getResult = (time) => {
        let result = 0;
        reqs.forEach(([a, b, c]) => {
            const tmp = time[c - 1];
            tmp.sort((a, b) => a - b);
            const idx = tmp.findIndex(t => t <= a);
            if (idx === -1) {
                result += tmp[0] - a;
                tmp[0] += b;
            } else {
                tmp[idx] = a + b;
            }
        });
        return result;
    };
    
    const makePermutate = () => {
        const result = [];
        const tmp = Array(k).fill(1);
        tmp[k - 1] += n - k;
        let idx = k - 1;
        if (k === n) return [tmp];
        while (1) {
            if (tmp[idx] < 1) {
                if (idx < 2) break ;
                tmp[idx - 2] += 1;
                for (let i = idx - 1; i < k; i++) {
                    tmp[i] = 1;
                }
                const sum = tmp.reduce((a, b) => a + b, 0);
                tmp[k - 1] += n - sum;
                if (tmp[k - 1] === 1) idx--;
                else idx = k - 1;
            }
            
            result.push(tmp.slice());
            if (idx < 1) break ;
            tmp[idx - 1] += 1;
            tmp[idx] -= 1;
        }
        return result;
    }

    const start = makePermutate();
    start.forEach(perm => {
        const time = Array.from(Array(k), (_, idx) => Array(perm[idx]).fill(0));
        const tmp = getResult(time);
        if (answer === -1 || answer > tmp) answer = tmp;
    });
    return answer;
}