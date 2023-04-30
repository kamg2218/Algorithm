function solution(users, emoticons) {
    var answer = [0, 0];
    
    const getPrice = (sales, rate) => {
        let sum = 0;
        sales.forEach((sale, idx) => {
            if (sale >= rate) sum += emoticons[idx] * (1 - sale / 100);
        })
        return sum;
    }
    
    
    const getResult = (sales) => {
        let result = [0, 0];
        users.forEach(([rate, price]) => {
            const tmp = getPrice(sales, rate);
            if (tmp >= price) result[0] += 1;
            else result[1] += tmp;
        })
        return result;
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