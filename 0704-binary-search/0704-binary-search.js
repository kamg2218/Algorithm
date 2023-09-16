/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    let left = 0;
    let right = nums.length;
    
    while (left < right) {
        const idx = Math.floor((left + right) / 2);
        
        if (nums[idx] === target) return idx;
        else if (nums[idx] > target) right = idx;
        else left = idx + 1;
    }

    return -1;
};