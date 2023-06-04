function solution(p) {
    let stack = [];
    let answer = '';
    
    const makeAlright = (str) => {
        const splitStack = str.split('');
        for (let i = 1; i < str.length - 1; i++) {
            splitStack[i] = splitStack[i] === '(' ? ')' : '(';
        }
        return splitStack.slice(1, splitStack.length - 1).join('');
    }
    
    const check = (str) => {
        const arr = [];
        for (let i = 0; i < str.length; i++) {
            if (arr.length) {
                str[i] === ')' ? arr.pop() : arr.push('(');
            } else if (str[i] === ')') {
                return false;
            } else {
                arr.push('(');
            }
        }
        return !arr.length;
    }
        
    const getResult = (p) => {
        for (let i = 0; i < p.length; i++) {
            if (stack.length && p[i] !== stack.at(-1)) {
                stack.pop();
            } else {
                stack.push(p[i]);
            }
            
            if (!stack.length) {
                const u = p.slice(0, i + 1);
                const v = p.slice(i + 1);
                if (check(u)) return u + getResult(v);
                else return '('+ getResult(v) + ')' + makeAlright(u);
            }
        }
        return '';
    }
    
    return getResult(p);
}