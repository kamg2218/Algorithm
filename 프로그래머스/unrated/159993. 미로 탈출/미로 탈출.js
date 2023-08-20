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
    
//     const answer = [-1, -1];
//     const dfs = ([sX, sY], visited, t) => {
//         if (sX === sle[0][0] && sY === sle[0][1]) {
//             answer[0] = (answer[0] === -1 || answer[0] > t) ? t : answer[0];
//             return ;
//         } else if (sX === sle[2][0] && sY === sle[2][1]) {
//             answer[1] = (answer[1] === -1 || answer[1] > t) ? t : answer[1];
//             return ;
//         }
        
//         visited[sX][sY] = 1;
//         dir.forEach(([x, y]) => {
//             if ((sX + x >= 0 && sX + x < row)
//                 && (sY + y >= 0 && sY + y < col)) {
//                 const value = maps[sX + x][sY + y];
                
//                 if (value === 'X') return ;
//                 else if (visited[sX + x][sY + y]) return ;
                
//                 dfs([sX + x, sY + y], visited, t + 1);
//             }
//         });
        
//         visited[sX][sY] = 0;
//     }

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
                // console.log(sX + x, sY + y, v);
                if (v === 0) stack.push([sX + x, sY + y]);
                board[sX + x][sY + y] = v ? Math.min(v, board[sX][sY] + 1) : board[sX][sY] + 1;
                // console.log(board);
            }
        });
    }
    // console.log(board);
    
    // dfs(sle[1], Array.from(Array(row), () => Array(col).fill(0)), 0);
    // console.log(answer)
    // if (answer[0] === -1 || answer[1] === -1) return -1;
    // return answer[0] + answer[1];
    
    if (!board[sle[0][0]][sle[0][1]] || !board[sle[2][0]][sle[2][1]]) return -1;
    
    return board[sle[0][0]][sle[0][1]] + board[sle[2][0]][sle[2][1]];
}