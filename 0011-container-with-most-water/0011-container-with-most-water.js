/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let max = 0;
    // for (let i = 0; i < height.length; i++) {
    //     for (let j = i + 1; j < height.length; j++) {
    //         const num = Math.min(height[i], height[j]) * (j - i);
    //         max = Math.max(max, num);
    //     }
    // }
    
    let left = 0;
    let right = height.length - 1;
    while (left < right) {
        const num = Math.min(height[left], height[right]) * (right - left);
        max = Math.max(max, num);
        
        if (height[left] <= height[right]) left++;
        else right--;
    }
    
    return max;
};