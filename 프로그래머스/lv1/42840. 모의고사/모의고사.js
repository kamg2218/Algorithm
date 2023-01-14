function solution(answers) {
    const rules = [
        [1, 2, 3, 4, 5],
        [2, 1, 2, 3, 2, 4, 2, 5],
        [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    ];
    
    const result = answers.reduce((arr, cur, idx) => {
        rules.forEach((v, i) => {
            if (v[idx % v.length] === cur) {
                arr[i] += 1;
            }
        })
        return arr;
    }, [0, 0, 0]);

    const max = Math.max(result[0], result[1], result[2]);
    return result.map((v, i) => {if (v === max) return i + 1}).filter(v => v);
}