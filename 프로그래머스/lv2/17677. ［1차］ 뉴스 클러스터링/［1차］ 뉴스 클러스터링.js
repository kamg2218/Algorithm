function solution(str1, str2) {
    const isAlpha = str => /^[a-zA-Z]*$/.test(str);
    
    const makeSlice = (str) => {
        const result = new Map();
        
        for (let i = 0; i < str.length; i++) {
            const tmp = str.toLowerCase().slice(i, i + 2);
            if (tmp.length === 2 && isAlpha(tmp)) {
                result.set(tmp, result.has(tmp) ? result.get(tmp) + 1 : 1);
            }
        }
        return result;
    }
    
    const intersection = (first, second) => {
        let cnt = 0;
        for (const [key, value] of first) {
            if (second.has(key)) {
                cnt += Math.min(value, second.get(key));
            }
        }
        return cnt;
    }
    
    const union = (first, second) => {
        let cnt = 0;
        for (const [key, value] of first) {
            if (second.has(key)) {
                cnt += Math.max(value, second.get(key));
            } else {
                cnt += value;
            }
        }
        for (const [key, value] of second) {
            if (!first.has(key)) {
                cnt += value;
            }
        }
        return cnt;
    }
    
    const first = makeSlice(str1);
    const second = makeSlice(str2);
    
    if (!first.size && !second.size) {
        return 65536;
    }
    
    const cnt_intersection = intersection(first, second);
    const cnt_union = union(first, second);
    
    return Math.floor(65536 * (cnt_intersection / cnt_union));
}