function solution(today, terms, privacies) {
    today = today.split('.').map(Number);
    
    const term = terms.reduce((acc, cur) => {
        const [type, period] = cur.split(' ');
        acc[type] = parseInt(period);
        return acc;
    }, {});
    
    return privacies.map((privacy, idx) => {
        const [date, type] = privacy.split(' ');
        const [year, month, day] = date.split('.').map(Number);
        const gap = (today[0] - year) * 12 + (today[1] - month);
        if (gap * 28 + today[2] - day >= term[type] * 28) return idx + 1;
        return null;
    }).filter(v => !!v);
}