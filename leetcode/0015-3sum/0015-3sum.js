/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    const result = new Set();
    const answer = [];
    
    nums.sort((a, b) => a - b);
    
    const findLastIndex = (num, last) => {
        for (let i = nums.length - 1; i >= 0; i--) {
            if (i <= last) return -1;
            if (num === nums[i]) return i;
        }
        return -1;
    }
    
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] > 0) break ;
        for (let j = i + 1; j < nums.length; j++) {
            const sum = nums[i] + nums[j];
            const idx = findLastIndex(-sum, j);
            if (idx > j) {
                const key = [nums[i], nums[j], nums[idx]].sort((a, b) => a - b);
                if (result.has(key.join(','))) continue ;
                answer.push(key);
                result.add(key.join(','));
            }
            while (j < nums.length && nums[j] === nums[j + 1]) j++;
        }
        while (i < nums.length && nums[i] === nums[i + 1]) i++;
    }
    return answer;
};