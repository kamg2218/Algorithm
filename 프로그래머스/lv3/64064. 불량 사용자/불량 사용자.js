function solution(user_id, banned_id) {
    var answer = new Set();
    const arr = [];
    
    const getUsers = (banned) => {
        const result = [];
        user_id.forEach((user, idx) => {
            if (user.length !== banned.length) return ;
            for (let i = 0; i < user.length; i++) {
                if (banned[i] === '*') continue ;
                if (banned[i] !== user[i]) return ;
            }
            result.push(idx);
        })
        return result;
    }
    
    const dfs = (idx, lst) => {
        if (idx === arr.length) {
            answer.add(lst.slice().sort().join(''));
            return ;
        }
        
        for (let i = 0; i < arr[idx].length; i++) {
            if (!lst.some(l => arr[idx][i] === l)) {
                lst.push(arr[idx][i]);
                dfs(idx + 1, lst);
                lst.pop();
            }
        }
    }
    
    banned_id.forEach(banned => arr.push(getUsers(banned)));
    dfs(0, []);
    return answer.size;
}