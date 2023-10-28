/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    const stack = [];
    
    s = s.split('');
    for (let i = 0; i < s.length; i++) {
        if (s[i] === '(' || s[i] === '{' || s[i] === '[') {
            stack.push(s[i]);
            continue;
        }
        
        if (s[i] === ')' && stack.at(-1) !== '(') return false;
        if (s[i] === '}' && stack.at(-1) !== '{') return false;
        if (s[i] === ']' && stack.at(-1) !== '[') return false;
        
        stack.pop();
    }
    return !stack.length;
};