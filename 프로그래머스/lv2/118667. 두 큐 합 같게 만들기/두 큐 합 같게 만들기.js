function solution(queue1, queue2) {
    var answer = 0;
    const max = queue1.length * 3;
    
    const sum = (arr) => {
        return arr.reduce((acc, cur) => cur + acc, 0);
    }
    
    let first = sum(queue1);
    let second = sum(queue2);
    if ((first + second) % 2) return -1;
    
    let first_idx = 0;
    let second_idx = 0;
    while (answer < max && first !== second) {
        if (first > second) {
            first -= queue1[first_idx];
            second += queue1[first_idx];
            queue2.push(queue1[first_idx++]);
        } else {
            first += queue2[second_idx];
            second -= queue2[second_idx];
            queue1.push(queue2[second_idx++]);
        }
        answer++;
    }
    return answer === max ? -1 : answer;
}