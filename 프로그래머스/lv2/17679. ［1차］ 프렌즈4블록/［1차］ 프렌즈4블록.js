function solution(m, n, board) {
    var answer = 0;
    const newBoard = board.map(row => row.split(''));
    
    const check = (x, y) => {
        if (x < 0 || y < 0 || x > m - 2 || y > n - 2) return false;
        if (newBoard[x][y] === '0') return false;
        
        return [newBoard[x][y + 1], newBoard[x + 1][y], newBoard[x + 1][y + 1]].every(char => char === newBoard[x][y]);
    }
    
    const remove = (x, y) => {
        const dir = [[0, 0], [0, 1], [1, 0], [1, 1]];
        dir.forEach(([a, b]) => {
            if (newBoard[x + a][y + b] === '0') return ;
            answer++;
            newBoard[x + a][y + b] = '0';
        });
    }
    
    const move = () => {
        let cnt = 0;
        for (let i = 1; i < m; i++) {
            for (let j = 0; j < n; j++) {
                if (newBoard[i][j] === '0' && newBoard[i - 1][j] !== '0') {
                    cnt++;
                    newBoard[i][j] = newBoard[i - 1][j];
                    newBoard[i - 1][j] = '0';
                }
            }
        }
        if (cnt) move();
    }
    
    while (true) {
        const stack = [];
        for (let i = 0; i < m - 1; i++) {
            for (let j = 0; j < n - 1; j++) {
                if (check(i, j)) stack.push({x: i, y: j});
            }
        }
        if (!stack.length) break;
        
        stack.forEach(({x, y}) => remove(x, y));
        move();
    }
    return answer;
}