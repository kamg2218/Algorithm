function solution(k, dungeons) {
    let max = 0;
    
    const check = (arr) => {
        let cnt = 0;
        let hp = k;
        
        for (let i = 0; i < arr.length; i++) {
            if (hp < dungeons[arr[i]][0]) {
                break ;
            }
            hp -= dungeons[arr[i]][1];
            cnt++;
        }
        if (max < cnt) {
            max = cnt;
        }
    }
    
    const dfs = (nums, num, len, arr = []) => {
        if (num === len) check(arr);
        else {
            for (let i = 0; i < nums.length; i++) {
                arr.push(nums[i]);
                const tmp = [...nums];
                tmp.splice(i, 1);
                dfs(tmp, num + 1, len, arr);
                arr.pop();
            }
        }
    };
    
    const initial = [];
    for (let i = 0; i < dungeons.length; i++) {
        initial.push(i);
    }
    
    dfs(initial, 0, dungeons.length);
    return max;
}