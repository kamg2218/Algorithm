/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
    const numbers = [...new Set(nums)];
    
    numbers.sort((a, b) => a - b);
    
    let max = 0;
    let cnt = 0;
    let last = Infinity;
    numbers.forEach(num => {
        if (num - last !== 1) {
            if (cnt > max) max = cnt;
            cnt = 0;
        }
        last = num;
        cnt++;
    });
    return Math.max(max, cnt);
};