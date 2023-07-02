function solution(rows, columns, queries) {
    const arr = Array.from(Array(rows), (_, row) => Array(columns).fill().map((_, col) => row * columns + col + 1));
    
    return queries.map(([startRow, startCol, endRow, endCol]) => {
        let tmp = arr[startRow - 1][startCol - 1];
        let min = tmp;
        // 오른쪽으로 이동
        for (let i = startCol; i < endCol; i++) {
            const value = tmp;
            tmp = arr[startRow - 1][i];
            if (tmp < min) min = tmp;
            arr[startRow - 1][i] = value;
        }
        
        // 오른쪽 아래로 이동
        for (let i = startRow; i < endRow; i++) {
            const value = tmp;
            tmp = arr[i][endCol - 1];
            if (tmp < min) min = tmp;
            arr[i][endCol - 1] = value;
        }
        
        // 왼쪽으로 이동
        for (let i = endCol - 2; i >= startCol - 1; i--) {
            const value = tmp;
            tmp = arr[endRow - 1][i];
            if (tmp < min) min = tmp;
            arr[endRow - 1][i] = value;
        }
        
        // 왼쪽 위로 이동
        for (let i = endRow - 2; i >= startRow - 1; i--) {
            const value = tmp;
            tmp = arr[i][startCol - 1];
            if (tmp < min) min = tmp;
            arr[i][startCol - 1] = value;
        }
        return min;        
    })    
}