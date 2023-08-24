/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var topKFrequent = function(nums, k) {
    const map = new Map();
    const answer = [];
    
    nums.forEach(num => {
        if (map.has(num)) {
            map.set(num, map.get(num) + 1);
        } else {
            map.set(num, 1);
        }
    });
    
    const frequentNumber = [...map.values()].sort((a, b) => b - a).at(k - 1);
    map.forEach((value, key) => {
        if (value >= frequentNumber) answer.push(key);
    });
    
    return answer;
};