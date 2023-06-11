function solution(plans) {
    const answer = [];
    const stack = [];
    
    const compare = (a, b) => {
        const [a_h, a_m] = a[1].split(':').map(Number);
        const [b_h, b_m] = b[1].split(':').map(Number);

        if (a_h > b_h || (a_h === b_h && a_m > b_m)) return 1;
        return -1;
    }
    
    const getDiff = (a, b) => {
        const [a_h, a_m] = a.split(':').map(Number);
        const [b_h, b_m] = b.split(':').map(Number);        
        return (b_h - a_h) * 60 + (b_m - a_m);
    }
    
    const addHour = (time, min) => {
        const [hour, minute] = time.split(':').map(Number);
        const new_min = minute + Number(min);
        return new_min >= 60 ? (hour + 1) + ':' + String(new_min - 60).padStart(2, '0') : hour + ':' + String(new_min).padStart(2, '0');
    }
    
    plans.sort(compare);
    
    stack.push(plans[0]);
    let time = plans[0][1];
    for (let i = 1; i < plans.length; i++) {
        const min = getDiff(time, plans[i][1]);
        if (stack.length && min) {
            const last = stack.at(-1);
            
            if (min >= Number(last[2])) {
                answer.push(last[0]);
                stack.pop();
                time = addHour(time, Number(last[2]));
                i--;
                continue ;
            } else {
                last[2] = String(Number(last[2]) - min);
            }
        }
        time = plans[i][1];
        stack.push(plans[i]);
    }
    
    while (stack.length) {
        const last = stack.at(-1);
        answer.push(last[0]);
        stack.pop();
    }
    return answer;
}