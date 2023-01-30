const direction = {
    "U": [0, 1],
    "D": [0, -1],
    "L": [-1, 0],
    "R": [1, 0],
}

function solution(dirs) {
    const road_width = new Set(); // x + y * 10
    const road_length = new Set(); // x * 10 + y
    let cur = [5, 5];
    
    const checkDir = (next) => {
        const small = (cur[0] < next[0] || (cur[0] === next[0] && cur[1] < next[1])) ? cur : next;
        if (cur[0] === next[0]) {
            const idx = small[0] * 10 + small[1];
            road_length.add(idx);
        }
        if (cur[1] === next[1]) {
            const idx = small[0] + small[1] * 10;
            road_width.add(idx);
        }
    }
    
    dirs.split('').forEach(dir => {
        const tmp = [cur[0] + direction[dir][0], cur[1] + direction[dir][1]];
        if (tmp[0] < 0 || tmp[0] > 10 || tmp[1] < 0 || tmp[1] > 10) {
            return ;
        }
        checkDir(tmp);
        cur = tmp;
    });
    return road_width.size + road_length.size;
}