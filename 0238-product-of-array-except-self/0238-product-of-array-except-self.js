/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
//     const mul = nums.reduce((acc, cur) => acc * cur, 1);
    
//     return nums.map(num => mul / num);
    
    return nums.map((num, idx) => {
        return nums.reduce((acc, cur, i) => {
            if (i === idx) return acc;
            return acc * cur;
        }, 1);
    });
};