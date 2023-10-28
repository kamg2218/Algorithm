/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    const reg = /[^a-zA-Z0-9]/g;
    s = s.replace(reg, '').toLowerCase();
    const len = s.length % 2 ? s.length / 2 + 1 : s.length / 2;
    return s.slice(len).split('').reverse().join('') === s.slice(0, s.length / 2);
};