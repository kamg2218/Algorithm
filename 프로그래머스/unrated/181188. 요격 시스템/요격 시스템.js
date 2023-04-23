function solution(targets) {
    targets.sort((a, b) => {
        if (a[0] < b[0]) return -1;
        if (a[0] === b[0] && a[1] < b[1]) return -1;
        return 0;
        
    });
    console.log(targets)
    
//     const findMaxLocation = () => {
//         const obj = {};
//         targets.forEach((target, idx) => {
//             const [start, end] = target;
//             for (let i = start; i < end; i++) {
//                 if (!obj[i]) obj[i] = [idx];
//                 else obj[i].push(idx);
//             }
//         });

//         let max = [];
//         Object.entries(obj).forEach(([key, value]) => {
//             if (value.length > max.length) max = value;
//         })
//         return max;
//     }
    
//     let cnt = 0;
//     while (targets.length) {
//         const arr = findMaxLocation();
//         targets = targets.filter((_, idx) => !arr.includes(idx));
//         cnt++;
//     }
    
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