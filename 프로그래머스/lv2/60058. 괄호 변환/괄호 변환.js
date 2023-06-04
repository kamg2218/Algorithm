function solution(p) {
    let stack = [];
    let answer = '';
    
    const makeAlright = (str, v) => {
        const splitStack = str.split('');
        const prev = '('+ getResult(v) + ')';
        
        for (let i = 1; i < str.length - 1; i++) {
            splitStack[i] = splitStack[i] === '(' ? ')' : '(';
        }
        return prev + splitStack.slice(1, splitStack.length - 1).join('');
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
    
    const getAnswer = (u, v) => {
        if (check(u)) return u + getResult(v);
        return makeAlright(u, v);
    }
    
    const getResult = (p) => {
        for (let i = 0; i < p.length; i++) {
            if (stack.length && p[i] !== stack.at(-1)) {
                    stack.pop();
            } else {
                stack.push(p[i]);
            }
            
            if (!stack.length) {
                return getAnswer(p.slice(0, i + 1), p.slice(i + 1));
            }
        }
        return '';
    }
    
    return getResult(p);
}