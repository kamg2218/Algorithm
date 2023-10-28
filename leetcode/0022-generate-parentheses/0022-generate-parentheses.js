/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    const answer = [];
    
    const makeStr = (lst) => {
        let check = 0;
        for (let i = 0; i < n * 2 - 1; i++) {
            if (lst.includes(i)) {
                check--;
                if (check < 0) return null;
            } else check++;
        }
        if (check !== 1) return null;
        
        let result = '(';
        for (let i = 1; i < n * 2 - 1; i++) {
            if (lst.includes(i)) result += ')';
            else result += '(';
        }
        return result + ')';
    }
    
    if (n === 1) {
        return ['()'];
    }
    
    const start = [];
    for (let i = 0; i < n - 1; i++) {
        start.push(n + i);
    }

    
    let idx = 0;
    while (1) {
        const result = makeStr(start);
        if (result) answer.push(result);
        
        while (idx > 0 && start[idx] - 1 === start[idx - 1]) idx--;
        start[idx] -= 1;
        for (let i = idx + 1; i < start.length; i++) {
            start[i] = n + i;
        }
        if (idx < start.length - 1) idx++;
        
        if (start[0] < 1) break;
    }
    return answer;
};