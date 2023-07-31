function solution(s, skip, index) {
    const str = 'abcdefghijklmnopqrstuvwxyz';
    const splitedStr = str.split('');

    return s.split('').map(c => {
        const idx = str.indexOf(c);
        let num = idx;
        for (let i = 0; i < index; i++) {
            num++;
            if (skip.includes(splitedStr[num % str.length])) {
                i--;
            }
        }
        return splitedStr[num % str.length];
    }).join('');    
}