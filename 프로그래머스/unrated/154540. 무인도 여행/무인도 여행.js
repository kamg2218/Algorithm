function solution(maps) {
    const answer = [];
    const row = maps.length;
    const col = maps[0].length;
    
    const splitedMap = maps.map(m => m.split(''));

    const dfs = (x, y) => {
        let count = Number(splitedMap[x][y]);
        
        splitedMap[x][y] = 'X';
        if (x > 0 && splitedMap[x - 1][y] !== 'X') count += dfs(x - 1, y);
        if (x < row - 1 && splitedMap[x + 1][y] !== 'X') count += dfs(x + 1, y);
        if (y > 0 && splitedMap[x][y - 1] !== 'X') count += dfs(x, y - 1);
        if (y < col - 1 && splitedMap[x][y + 1] !== 'X') count += dfs(x, y + 1);
        return count;
    }
    
    for (let i = 0; i < row; i++) {
        for (let j = 0; j < col; j++) {
            if (splitedMap[i][j] !== 'X') answer.push(dfs(i, j));
        }
    }
    answer.sort((a, b) => a - b);
    return answer.length ? answer : [-1];
}