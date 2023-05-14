function solution(survey, choices) {
    var answer = {
        'R':0,
        'T':0,
        'C':0,
        'F':0,
        'J':0,
        'M':0,
        'A':0,
        'N':0,
    };
    const list = ['RT', 'CF', 'JM', 'AN'];
    
    survey.forEach((score, idx) => {
        if (choices[idx] < 4) {
            answer[score[0]] += 4 - choices[idx];
        } else if (choices[idx] > 4) {
            answer[score[1]] += choices[idx] - 4;
        }
    });
    
    return list.map(str => {
        if (answer[str[0]] >= answer[str[1]]) return str[0];
        return str[1];
    }).join('');
}