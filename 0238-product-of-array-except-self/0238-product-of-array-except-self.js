/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    return nums.map((num, idx) => nums.reduce((acc, cur, i) => {
        if (i === idx) return acc;
        return acc * cur;
    }, 1));
};