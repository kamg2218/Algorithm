function solution(topping) {
    var answer = 0;
    const right = new Map();
    const left = new Set();
    
    topping.forEach(top => {
        if (right.has(top)) right.set(top, right.get(top) + 1);
        else right.set(top, 1);
    });
    topping.forEach(top => {
        left.add(top);
        right.set(top, right.get(top) - 1);
        if (right.get(top) === 0) right.delete(top);
        if (left.size === right.size) answer++;
    })
    return answer;
}