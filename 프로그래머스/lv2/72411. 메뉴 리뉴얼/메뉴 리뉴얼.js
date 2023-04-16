function solution(orders, course) {
    var answer = [];
    
    const getCombinations = (str, cnt) => {
        const result = [];
        
        if (cnt < 1) return [];
        if (cnt === 1) return str.split('');
        str.split('').forEach((value, idx) => {
            const sliced = str.slice(idx + 1);
            const combination = getCombinations(sliced, cnt - 1);
            combination.forEach(com => {
                const arrangedStr = (value + com).split('').sort().join('');
                result.push(arrangedStr)
            });
        })
        return result;
    }
    
    course.forEach(num => {
        const map = new Map();
        orders.forEach(order => {
            const combination = getCombinations(order, num);
            combination.forEach(comb => {
                if (map.has(comb)) map.set(comb, map.get(comb) + 1);
                else map.set(comb, 1);
            })
        });
        
        let max = 0;
        map.forEach(v => {
            if (v > max) max = v;
        });
        
        if (max < 2) return ;
        map.forEach((v, k) => {
            if (v === max) answer.push(k);
        })
    })
    return answer.sort();
}