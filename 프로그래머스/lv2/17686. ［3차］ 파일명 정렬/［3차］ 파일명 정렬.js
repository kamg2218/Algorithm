function solution(files) {
    const regExp = '[0-9]';
    
    const divider = (str) => {
        const start = str.search(regExp);
        const header = str.slice(0, start).toLowerCase();
        const body = parseInt(str.slice(start));
        return {header, body};
    }
    
    files.sort((a, b) => {
        const a_result = divider(a);
        const b_result = divider(b);
        
        if (a_result.header > b_result.header) return 1;
        if (a_result.header < b_result.header) return -1;
        if (parseInt(a_result.body) > parseInt(b_result.body)) return 1;
        if (parseInt(a_result.body) < parseInt(b_result.body)) return -1;
        
        return 0;
    })
    return files;
}