/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    if (s.length !== t.length) return false;
    
    const splitedS = s.split('').sort();
    const splitedT = t.split('').sort();
    
    for (let i = 0; i < s.length; i++) {
        if (splitedS[i] !== splitedT[i]) return false;
    }
    return true;
};