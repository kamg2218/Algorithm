function solution(targets) {
    targets.sort((a, b) => {
        if (a[0] < b[0]) return -1;
        if (a[0] === b[0] && a[1] < b[1]) return -1;
        return 0;
        
    });
    
    let cnt = 1;
    let num = [-1, -1];
    for (let i = 0; i < targets.length; i++) {
        if (num[0] === -1) {
            num = targets[i];
            continue ;
        }
        if (num[0] < targets[i][0] && targets[i][0] < num[1]) num[0] = targets[i][0];
        if (num[1] > targets[i][1] && targets[i][1] > num[0]) num[1] = targets[i][1];
        
        if (num[0] === targets[i][0] || num[1] === targets[i][1]) continue ;
        
        cnt++;
        num = targets[i];
    }
    
    return cnt;
}