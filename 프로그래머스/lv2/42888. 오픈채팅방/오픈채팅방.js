function solution(record) {
    const nickname = new Map();
    
    record.forEach(words => {
        const [cmd, uid, name] = words.split(' ');
        
        if (!name) {
            return ;
        }
        nickname.set(uid, name);
    });
    
    return record.reduce((acc, cur) => {
        const [cmd, uid, name] = cur.split(' ');
        
        if (cmd === 'Enter') {
            acc.push(nickname.get(uid) + '님이 들어왔습니다.');
        } else if (cmd === 'Leave') {
            acc.push(nickname.get(uid) + '님이 나갔습니다.');
        }
        return acc;
    }, []);
}