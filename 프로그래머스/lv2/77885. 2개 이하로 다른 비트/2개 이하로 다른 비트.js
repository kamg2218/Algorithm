function solution(numbers) {    
    return numbers.map(num => {
        if (num % 2 === 0) return num + 1;
        const str = '0' + num.toString(2);
        for (let i = str.length - 1; i >= 0; i--) {
            if (str[i] === '0') {
                return parseInt(str.slice(0, i) + str[i + 1] + str[i] + str.slice(i + 2), 2);
            }
        }
    });
}