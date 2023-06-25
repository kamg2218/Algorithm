function solution(park, routes) {
    const answer = [];
    const row = park.length;
    const col = park[0].length;
    
    const dir = {
        'E': [0, 1],
        'W': [0, -1],
        'N': [-1, 0],
        'S': [1, 0],
    }
    
    park.forEach((row, idx) => {
        if (row.includes('S')) {
            answer.push(idx);
            answer.push(row.indexOf('S'));
        }
    });
    
    park = park.map(p => p.split(''));
    
    routes.forEach(route => {
        const cmd = route.split(' ');
        const num = Number(cmd[1]);
        const d = dir[cmd[0]];
        const r = [answer[0] + d[0] * num, answer[1] + d[1] * num];
        if (r[0] < 0 || r[0] >= row || r[1] < 0 || r[1] >= col) return ;
        for (let i = 1; i <= num; i++) {
            if (park[answer[0] + d[0] * i][answer[1] + d[1] * i] === 'X') return;
        }
        answer[0] += d[0] * num;
        answer[1] += d[1] * num;
    })
    
    return answer;
}