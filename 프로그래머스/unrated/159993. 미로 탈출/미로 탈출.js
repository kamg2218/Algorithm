function solution(maps) {
    const row = maps.length;
    const col = maps[0].length;
    const dir = [
        [0, 1],
        [0, -1],
        [1, 0],
        [-1, 0],
    ];
        
    const sle = [];
    const board = Array.from(Array(row), () => Array(col).fill(0));
    
    maps.forEach((map, i) => {
        map.split('').forEach((m, j) => {
            if (m === 'S') sle[0] = [i, j];
            else if (m === 'L') sle[1] = [i, j];
            else if (m === 'E') sle[2] = [i, j];
            else if (m === 'X') board[i][j] = -1;
        })
    });

    const stack = [sle[1]];
    while (!!stack.length) {
        const [sX, sY] = stack.shift();
        dir.forEach(([x, y]) => {
            if ((sX + x >= 0 && sX + x < row)
                && (sY + y >= 0 && sY + y < col)) {
                const v = board[sX + x][sY + y];
                if (v === -1) return ;
                if (v === 0) stack.push([sX + x, sY + y]);
                board[sX + x][sY + y] = v ? Math.min(v, board[sX][sY] + 1) : board[sX][sY] + 1;
            }
        });
    }

    if (!board[sle[0][0]][sle[0][1]] || !board[sle[2][0]][sle[2][1]]) return -1;
    return board[sle[0][0]][sle[0][1]] + board[sle[2][0]][sle[2][1]];
}