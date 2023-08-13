function solution(arr) {
    var answer = [0, 0];
    
    const check = (start, size) => {
        const [x, y] = start;
        const num = arr[x][y];
        for (let i = x; i < x + size; i++) {
            for (let j = y; j < y + size; j++) {
                if (num !== arr[i][j]) return false;
            }
        }
        return true;
    }
    
    const dfs = (start, size) => {
        if (check(start, size)) {
            return arr[start[0]][start[1]] ? answer[1]++ : answer[0]++;
        }
        const [x, y] = start;
        const halfSize = Math.floor(size / 2);
        dfs(start, size/2);
        dfs([x + halfSize, y], halfSize);
        dfs([x, y + halfSize], halfSize);
        dfs([x + halfSize, y + halfSize], halfSize);
    }
    
    dfs([0, 0], arr.length);
    return answer;
}