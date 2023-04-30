function solution(users, emoticons) {
    var answer = [0, 0];
    
    const getPrice = (sales, rate) => {
        return sales.reduce((acc, cur, idx) => {
            if (cur >= rate) acc += emoticons[idx] * (1 - cur / 100);
            return acc;
        }, 0);
    }
    
    const getResult = (sales) => {
        return users.reduce((acc, cur) => {
            const [rate, price] = cur;
            const tmp = getPrice(sales, rate);
            if (tmp >= price) acc[0] += 1;
            else acc[1] += tmp;
            return acc;
        }, [0, 0]);
    }
    
    const changeSales = (sales) => {
        let idx = sales.length - 1;
        
        while (idx >= 0 && sales[idx] === 40) idx--;
        if (idx === -1) return [];
        
        sales[idx++] += 10;
        while (idx < sales.length) sales[idx++] = 10;
        
        return sales;
    }
    
    let sales = Array(emoticons.length).fill(10);
    while (sales.length) {
        const tmp = getResult(sales);
        if (tmp[0] > answer[0]) answer = tmp;
        else if (tmp[0] === answer[0] && tmp[1] > answer[1]) answer = tmp;
        
        sales = changeSales(sales);
    }
    
    return answer;
}