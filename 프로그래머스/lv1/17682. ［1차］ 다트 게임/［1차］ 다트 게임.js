function solution(dartResult) {
    const result = [];
    
    const exponent = {
        'S': 1,
        'D': 2,
        'T': 3,
    }
    const bonus = {
        '*': 2,
        '#': -1,
    }
    
    const dart = dartResult.split(/[S|D|T|*|#]/).filter(value => value).map(Number);
    const character = dartResult.split(/\d/).filter(value => value);

    for (let i = 0; i < dart.length; i++) {
        result.push(Math.pow(dart[i], exponent[character[i][0]]));
        if (character[i].length > 1) {
            result[result.length - 1] *= bonus[character[i][1]];
            if (result.at(-2) !== undefined && character[i][1] === '*') {
                result[result.length - 2] *= bonus[character[i][1]];
            }
        }
    }
    let answer = 0;
    result.forEach(num => answer += num)
    return answer;
}