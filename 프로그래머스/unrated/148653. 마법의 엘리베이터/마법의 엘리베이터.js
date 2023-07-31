function solution(storey) {
    const str = storey.toString().split('').map(Number);
    str.unshift(0);
    
    const dfs = (idx, sum) => {
        if (idx === 0) return sum + str[idx];
        
        if (str[idx] === 10) {
            str[idx - 1] += 1;
            str[idx] -= 10;
            return dfs(idx - 1, sum);
        }
        if (str[idx] > 5 || (str[idx] === 5 && str[idx - 1] >= 5)) {
            str[idx - 1] += 1;
            return dfs(idx - 1, sum + 10 - str[idx]);
        }
        return dfs(idx - 1, sum + str[idx]);
    }        
    return dfs(str.length - 1, 0);
}