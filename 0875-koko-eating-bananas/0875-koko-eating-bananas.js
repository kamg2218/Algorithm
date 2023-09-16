/**
 * @param {number[]} piles
 * @param {number} h
 * @return {number}
 */
var minEatingSpeed = function(piles, h) {
    let result = 0;
    
    for (let i = 0; i < piles.length; i++) {
        if (result < piles[i]) result = piles[i];
    }
    
    const check = (num) => {
        let cnt = 0;
        for (let i = 0; i < piles.length; i++) {
            cnt += Math.ceil(piles[i] / num);
        }
        return cnt;
    }
    
    let left = 0;
    let right = result;
    while (left < right) {
        const idx = Math.floor((left + right) / 2);
        const cnt = check(idx);
        
        if (cnt <= h && result > idx) result = idx;
        else if (cnt > h) left = idx + 1;
        else right = idx;        
    }
    return result;
};