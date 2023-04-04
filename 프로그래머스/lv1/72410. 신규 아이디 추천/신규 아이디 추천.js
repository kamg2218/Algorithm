function solution(new_id) {
    const regExp = '[a-z 0-9 \_.-]';
    
    let result = new_id.toLowerCase().split('').filter(s => s.match(regExp)).join('');
    
    const replace = (before, after) => {
        let tmp = result.replaceAll(before, after);
        while (tmp !== result) {
            result = tmp;
            tmp = tmp.replaceAll(before, after);
        }
    }
    
    replace('..', '.');
    if (result[0] === '.') result = result.slice(1);
    if (result.at(-1) === '.') result = result.slice(0, -1);
    if (result.length === 0) result = 'a';
    if (result.length > 15) result = result.slice(0, 15);
    if (result[0] === '.') result = result.slice(1);
    if (result.at(-1) === '.') result = result.slice(0, -1);
    if (result.length < 3) result += String(result.at(-1)).repeat(3 - result.length);
    return result;
}