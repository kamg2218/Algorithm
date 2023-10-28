/**
 * @param {number[]} temperatures
 * @return {number[]}
 */
var dailyTemperatures = function(temperatures) {
    const stack = [];
    const result = [];
    
    for (let i = 0; i < temperatures.length; i++) {
        while (stack.length && temperatures[stack.at(-1)] < temperatures[i]) {
            const j = stack.pop();
            result[j] = i - j;
        }        
        stack.push(i);
    }
    stack.forEach(idx => result[idx] = 0);
    return result;
};