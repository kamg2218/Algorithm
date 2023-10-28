/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let left = 0;
    let right = 1;
    let answer = 1;
    let record = new Map();
    
    if (s.length === 0) return 0;
    record.set(s[left], s[left]);
    while (right < s.length) {
        if (record.has(s[right])) {
            record.delete(s[left]);
            left++;
            continue ;
        }
        record.set(s[right], s[right]);
        if (record.size > answer) {
            answer = record.size;
        }
        right++;
    }
    return answer;
};