function solution(cap, n, deliveries, pickups) {
    var answer = 0;
    let last_del = n;
    let last_pick = n;
    
    const getDistance = (list, name) => {
        let start = 0;
        let cnt = 0;
        
        for (let i = name === 'pick' ? last_pick : last_del; i >= 0; i--) {
            if (cnt === cap) {
                return start;
            }
            if (list[i] > 0) {
                if (!start) {
                    start = i + 1;
                }
                const tmp = cap - cnt > list[i] ? list[i] : cap - cnt;
                cnt += tmp;
                list[i] -= tmp;
                name === 'pick' ? last_pick = i : last_del = i;
            }
        }
        return start;
    }
    
    while (1) {
        const del = getDistance(deliveries, 'del');
        const pick = getDistance(pickups, 'pick');
        
        if (!del && !pick) {
            break ;
        }
        answer += Math.max(del, pick) * 2;
    }
    return answer;
}