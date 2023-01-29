function solution(msg) {
    const answer = [];
    const dict = new Map();
    let last = 27;
    
    // A ~ Z
    for (let i = 1; i < 27; i++) {
        dict.set(String.fromCharCode(i + 64), i);
    }
    
    for (let idx = 0; idx < msg.length; idx++) {
        let word = msg.at(idx);
        for (let i = 1; i <= msg.length - idx; i++) {
            const newWord = msg.slice(idx, idx + i);
            if (!dict.has(newWord)) {
                dict.set(newWord, last++);
                answer.push(dict.get(word));
                idx += i - 2;
                break ;
            }
            word = newWord;
            if (i === msg.length - idx) {
                answer.push(dict.get(word));
                idx = msg.length;
            }
        }
    }
    return answer;
}
