function solution(gems) {
    const types = new Set(gems).size;
    const map = new Map();
    let result = [1, gems.length];
    
    const add = (key) => {
        if (map.has(key)) {
            map.set(key, map.get(key) + 1);
        } else {
            map.set(key, 1);
        }
    }
    const sub = (key) => {
        if (map.has(key)) {
            map.set(key, map.get(key) - 1);
        }
        if (map.get(key) === 0) {
            map.delete(key);
        }
    }
    
    let start = 0;
    let end = 0;
 
    while (start < gems.length - types + 1 && end < gems.length) {
        add(gems[end]);
        while (map.get(gems[start]) > 1) {
            sub(gems[start]);
            start += 1;
        }
        if (map.size === types && result[1] - result[0] > end - start) {
            result = [start + 1, end + 1];
            sub(gems[start]);
            start += 1;
        }
         end++;
    }
    
    return result;
}

// function solution(gems) {
//     const types = new Set(gems).size;    
//     if (types === 1) return [1, 1];
//     for (let len = types; len <= gems.length; len++) {
//         for (let idx = 0; idx <= gems.length - len; idx++) {
//             const sliced = gems.slice(idx, idx + len);
//             if (new Set(sliced).size === types) {
//                 return [idx + 1, idx + len];
//             }
//         }
//     }
//     return [1, gems.length];
// }