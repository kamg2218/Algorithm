function solution(s, skip, index) {
    const str = 'abcdefghijklmnopqrstuvwxyz';
    const splitedStr = str.split('');

    var answer = '';
    
    s.split('').forEach(c => {
        const idx = str.indexOf(c);
        let num = idx;
        for (let i = 0; i < index; i++) {
            num++;
            if (skip.includes(splitedStr[num % str.length])) {
                i--;
            }
        }
        answer += splitedStr[num % str.length];
    });    
    return answer;
}