/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    const group = new Map();
    
    strs.forEach(str => {
        const key = str.split('').sort().join('');
        if (group.has(key)) group.set(key, [...group.get(key), str]);
        else group.set(key, [str]);
    });
    return [...group.values()];
};