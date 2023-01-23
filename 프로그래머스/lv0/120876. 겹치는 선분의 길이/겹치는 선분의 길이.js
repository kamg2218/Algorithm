function solution(lines) {
    const map = new Map();
    
    lines.forEach(([start, end]) => {
        for (let i = start; i < end; i++) {
            map.has(i) ? map.set(i, map.get(i) + 1) : map.set(i, 1); 
        }
    });
    return [...map].filter(a => a[1] >= 2).length;
}