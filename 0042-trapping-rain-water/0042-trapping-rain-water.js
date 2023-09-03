/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function(height) {
    let answer = 0;
    
    let left = 0;
    let right = 0;
    while (left < height.length) {
        while (height[left] <= height[left + 1]) left++;
        right = left + 1;
        let mid = right;
        while (height[left] >= height[right]) {
            if (height[mid] < height[right]) mid = right;
            right++;
        }
        if (right === height.length) {
            right = mid;
        }
        
        const min = Math.min(height[left], height[right]);
        for (let i = left + 1; i < right; i++) {
            answer += min - height[i];
        }
        left = right;
    }
    
    return answer;
};