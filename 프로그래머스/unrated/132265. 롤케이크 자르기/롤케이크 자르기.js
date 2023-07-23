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

    // topping.forEach((top, idx) => {
    //     const first = new Set(topping.slice(0, idx + 1)).size;
    //     const second = new Set(topping.slice(idx + 1)).size;
    //     if (first === second) answer++;
    // })
    