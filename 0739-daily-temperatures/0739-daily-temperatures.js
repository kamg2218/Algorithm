/**
 * @param {number[]} temperatures
 * @return {number[]}
 */
var dailyTemperatures = function(temperatures) {
    const getIndex = (start, num) => {
        for (let i = start; i < temperatures.length; i++) {
            if (temperatures[i] > num) return i;
        }
        return -1;
    }
    
    return temperatures.map((temp, i) => {
        const idx = getIndex(i + 1, temp);
        if (idx === -1) return 0;
        return idx - i;
    });
};