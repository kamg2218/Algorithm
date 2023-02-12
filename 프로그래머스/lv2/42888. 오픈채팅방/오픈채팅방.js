function solution(record) {
    const nickname = new Map();
    
    record.forEach(words => {
        const [cmd, uid, name] = words.split(' ');
        
        if (!name) {
            return ;
        }
        nickname.set(uid, name);
    });
    
    return record.map(words => {
        const [cmd, uid, name] = words.split(' ');
        
        if (cmd === 'Enter') {
            return nickname.get(uid) + '님이 들어왔습니다.';
        } else if (cmd === 'Leave') {
            return nickname.get(uid) + '님이 나갔습니다.';
        }
        return ;
    }).filter(v => v);
}