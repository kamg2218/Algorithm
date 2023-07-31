function solution(expression) {
    var answer = 0;
    
    let arr = ['*', '+', '-'];
    const numbers = expression.split(/[*+-]/).map(Number);
    const operations = expression.split(/\d/).filter(v => !!v);
    
    const getNumber = (a, b, op) => {
        if (op === '*') return a * b;
        if (op === '+') return a + b;
        if (op === '-') return a - b;
    }
    
    const getResult = (order, numbers, operators) => {
        order.forEach(operator => {
            while (1) {
                const idx = operators.findIndex(v => v === operator);
                if (idx === -1) break ;
                else {
                    numbers[idx] = getNumber(numbers[idx], numbers[idx + 1], operator);
                    numbers.splice(idx + 1, 1);
                    operators.splice(idx, 1);
                }
            }
        });
        return Math.abs(numbers[0]);
    }
    
    const permutation = (arr, num) => {
        const res = [];
        if(num === 1) return arr.map((v) => [v]);

        arr.forEach((v, idx, arr) => {
            const rest = [...arr.slice(0,idx), ...arr.slice(idx+1)];
            const permutations = permutation(rest, num-1);
            const attach = permutations.map((permutation) => [v, ...permutation]);
            res.push(...attach);
        });
        return res;
    }
    
    const orders = permutation(arr, 3);
    orders.forEach(order => {
        const tmp = getResult(order, numbers.slice(), operations.slice());
        if (answer < tmp) answer = tmp;
    });    
    return answer;
}