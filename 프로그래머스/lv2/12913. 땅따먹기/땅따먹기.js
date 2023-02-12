function solution(land) {
    const board = Array.from(Array(land.length), () => Array(land[0].length).fill(0));
    
    const getMax = (line, except) => {
        return line.reduce((acc, cur, idx) => {
            if (acc < cur && idx !== except) {
                return cur;
            }
            return acc;
        }, 0);
    };
    
    land.forEach((v, i) => {
        if (i === 0) {
            board[i] = land[i];
            return ;
        } else {
            v.forEach((num, j) => {
                board[i][j] = num + getMax(board[i - 1], j);
            })
        }
    })
    return getMax(board[board.length - 1], -1);
}