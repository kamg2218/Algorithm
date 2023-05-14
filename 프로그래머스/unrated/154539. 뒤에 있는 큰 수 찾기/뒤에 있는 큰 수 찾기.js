function solution(numbers) {
    var answer = Array(numbers.length).fill(-1);
    
    const tmp = [0];
    for (let i = 1; i < numbers.length; i++) {
        const last = tmp.at(-1);
        if (tmp.length && numbers[last] < numbers[i]) {
            answer[last] = numbers[i];
            tmp.pop();
            i -= 1;
        } else tmp.push(i);
    }
    return answer;
}