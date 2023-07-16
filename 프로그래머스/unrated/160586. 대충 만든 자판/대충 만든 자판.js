function solution(keymap, targets) {
   return targets.map(target => {
        const t = target.split('').reduce((acc, cur) => {
            const result = keymap.map(key => key.indexOf(cur) === -1 ? Infinity : key.indexOf(cur));
            result.sort((a, b) => a - b);
            return acc + 1 + result.at(0);
        }, 0);
        return t === Infinity ? -1 : t;
    });
}