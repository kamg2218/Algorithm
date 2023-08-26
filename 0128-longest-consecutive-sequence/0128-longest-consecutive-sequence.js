/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
    let max = 0;
    let cnt = 0;
    let last = Infinity;

    [...new Set(nums)].sort((a, b) => a - b).forEach(num => {
        if (num - last !== 1) {
            if (cnt > max) max = cnt;
            cnt = 0;
        }
        last = num;
        cnt++;
    });
    return Math.max(max, cnt);
};