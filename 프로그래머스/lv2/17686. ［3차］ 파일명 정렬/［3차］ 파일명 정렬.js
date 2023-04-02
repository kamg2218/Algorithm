function solution(files) {
    const regExp = '[0-9]';
    
    const divider = (str) => {
        const start = str.search(regExp);
        
        let end = start + 1;
        while (end < str.length) {
            if (!str[end].match(regExp)) break ;
            end++;
        }
        
        const header = str.slice(0, start).toLowerCase();
        const body = str.slice(start, end).toLowerCase();
        const tail = str.slice(end).toLowerCase();
        return {header, body, tail};
    }
    
    const answer = files.slice();
    answer.sort((a, b) => {
        const a_result = divider(a);
        const b_result = divider(b);
        
        if (a_result.header > b_result.header) return 1;
        if (a_result.header < b_result.header) return -1;
        if (parseInt(a_result.body) > parseInt(b_result.body)) return 1;
        if (parseInt(a_result.body) < parseInt(b_result.body)) return -1;
        if (files.findIndex(i => i === a) > files.findIndex(i => i === b)) return 1;
        
        return -1;
    })
    return answer;
}