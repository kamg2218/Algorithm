function solution(X, Y) {
    const mapX = new Map();
    const mapY = new Map();
    const common = new Map();
    
    X.split('').forEach(x => mapX.has(x) ? mapX.set(x, mapX.get(x) + 1) : mapX.set(x, 1));
    Y.split('').forEach(y => mapY.has(y) ? mapY.set(y, mapY.get(y) + 1) : mapY.set(y, 1));
    
    mapX.forEach((v, k) => {
        if (mapY.has(k)) {
            common.set(k, Math.min(v, mapY.get(k)));
        }
    });

    if (!common.size) return "-1";
    else if (common.size === 1 && common.has('0')) return "0";
    
    const result = [];
    common.forEach((v, k) => {
        for (let i = 0; i < v; i++) {
            result.push(k);
        }
        // result.push(...k.repeat(v).split(''));
    })
    result.sort((a, b) => b - a);
    
    return result.join('');
}