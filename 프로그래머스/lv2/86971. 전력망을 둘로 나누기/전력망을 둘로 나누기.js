let cnt = 1;

const dfs = (idx, n, board, visited) => {
    if (visited[idx]) {
        return ;
    }
    visited[idx] = 1;
    for (let i = 1; i < n + 1; i++) {
        if (idx === i) {
            continue ;
        }
        if (!visited[i] && board[idx][i]) {
            dfs(i, n, board, visited);
            cnt++;
        }
    }
}

const getWires = (n, wires) => {
    const board = Array.from(Array(n + 1), () => Array(n + 1).fill(0));
    
    wires.forEach(wire => {
        board[wire[0]][wire[1]] = 1;
        board[wire[1]][wire[0]] = 1;
    });
    const visited = Array(n + 1).fill(0);
    cnt = 1;
    dfs(wires[0][0], n, board, visited);
    return Math.abs(n - 2 * cnt);
}

function solution(n, wires) {
    let answer = n;
    for (let i = 0; i < n - 1; i++) {
        const splicedWire = [...wires];
        splicedWire.splice(i, 1);
        const result = getWires(n, splicedWire);
        if (result < answer) {
            answer = result;
        }
    }
    return answer;
}