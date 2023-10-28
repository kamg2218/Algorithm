/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let left = 0;
    let right = 1;
    let answer = 0;
    
    while (right < prices.length) {
        if (prices[left] > prices[right]) {
            left = right;
            right++;
            continue ;
        }
        const result = prices[right] - prices[left];
        if (result > answer) {
            answer = result;
        }
        right++;
    }
    return answer;
};