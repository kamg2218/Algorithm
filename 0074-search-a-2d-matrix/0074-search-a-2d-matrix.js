/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    let [rowLen, colLen] = [matrix.length, matrix[0].length];
    let row = -1;
    
    for (let i = 0; i < rowLen; i++) {
        if (matrix[i][colLen - 1] >= target) {
            row = i;
            break ;
        }
    }

    if (row === -1) return false;

    let left = 0;
    let right = colLen;
    while (left < right) {
        const idx = Math.floor((left + right) / 2);
        if (matrix[row][idx] === target) return true;
        else if (matrix[row][idx] > target) right = idx;
        else left = idx + 1;
    }
    return false;
};