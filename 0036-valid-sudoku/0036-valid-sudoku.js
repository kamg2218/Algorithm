/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function(board) {
    //row    
    for (let i = 0; i < 9; i++) {
        const nums = new Set();
        for (let j = 0; j < 9; j++) {
            if (isNaN(board[i][j])) continue ;
            if (nums.has(board[i][j])) return false;
            nums.add(board[i][j]);
        }
    }
    //col
    for (let i = 0; i < 9; i++) {
        const nums = new Set();
        for (let j = 0; j < 9; j++) {
            if (isNaN(board[j][i])) continue ;
            if (nums.has(board[j][i])) return false;
            nums.add(board[j][i]);
        }
    }
    //box
    const checkBox = (x, y) => {
        const nums = new Set();
        for (let i = x; i < x + 3; i++) {
            for (let j = y; j < y + 3; j++) {
                if (isNaN(board[i][j])) continue ;
                if (nums.has(board[i][j])) return false;
                nums.add(board[i][j]);
            }
        }
        return true;
    }
    
    for (let i = 0; i < 9; i += 3) {
        for (let j = 0; j < 9; j += 3) {
            if (!checkBox(i, j)) return false;
        }
    }
    
    return true;
};