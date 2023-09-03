/**
 * @param {string[]} tokens
 * @return {number}
 */
var evalRPN = function(tokens) {
    const stack = [];
    
    const cal = (eq, l, r) => {
        if (eq === '*') return l * r;
        else if (eq === '/') {
            const result = l / r;
            return result > 0 ? Math.floor(result) : Math.ceil(result);
        } else if (eq === '+') return l + r;
        else if (eq === '-') return l - r;
    }
        
    tokens.forEach((token) => {
        if (isNaN(Number(token))) {
            const r = stack.pop();
            const result = cal(token, stack.pop(), r);
            stack.push(result);
        } else {
            stack.push(Number(token));
        }
    });
    return stack.at(0);
};