function solution(expression) {
    var answer = 0;
    
    const orders = [
        ['*', '+', '-'],
        ['*', '-', '+'],
        ['+', '*', '-'],
        ['+', '-', '*'],
        ['-', '+', '*'],
        ['-', '*', '+'],
    ];
    
    const numbers = expression.split(/[*+-]/).map(Number);
    const operations = expression.split(/\d/).filter(v => !!v);
    
    const getNumber = (a, b, op) => {
        if (op === '*') return a * b;
        if (op === '+') return a + b;
        if (op === '-') return a - b;
    }
    
    // 우선 순위 연산
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
    
    // 후위표기식    
//     const getResult = (order, numbers, operators) => {
//         let num_stack = [numbers[0]];
//         const op_stack = [operators[0]];
        
//         for (let i = 1; i < numbers.length; i++) {
//             num_stack.push(numbers[i]);
//             while (op_stack.length && order.findIndex(o => o === op_stack.at(-1)) <= order.findIndex(o => o === operators[i])) {
//                 num_stack.push(op_stack.pop());
//             }
//             if (i < numbers.length - 1) {
//                 op_stack.push(operators[i]);
//             }
//         }
//         num_stack = num_stack.concat(op_stack.reverse());

//         for (let i = 0; i < num_stack.length; i++) {
//             if (Number.isInteger(num_stack[i])) continue;
            
//             const tmp = getNumber(num_stack[i - 2], num_stack[i - 1], num_stack[i]);
//             num_stack.splice(i - 2, 3, tmp);
//             i -= 2;
//         }
//         return Math.abs(num_stack[0]);
//     }
    
    orders.forEach(order => {
        const tmp = getResult(order, numbers.slice(), operations.slice());
        if (answer < tmp) answer = tmp;
    });    
    return answer;
}