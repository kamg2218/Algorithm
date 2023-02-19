function solution(want, number, discount) {
    var answer = 0;
    const board = new Map();
    
    const check = () => {
        const cnt = want.filter((w, idx) => board.get(w) === number[idx]);
        return cnt.length === want.length ? 1 : 0;
    }
    
    const add = (product) => {
        if (board.has(product)) {
            board.set(product, board.get(product) + 1);
        } else {
            board.set(product, 1);
        }   
    }
    
    discount.forEach((product, idx) => {
        if (idx < 10) add(product);
        if (idx === 9 && check()) answer++;
        if (idx > 9) {
            const tmp = discount[idx - 10];
            board.set(tmp, board.get(tmp) - 1);
            add(product);
            if (check()) answer++;
        }
    });
    return answer;
}