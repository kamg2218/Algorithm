function solution(number, k) {
    let cnt = 0;
    const stack = [];
        
    for (num of number) {
        while (1) {
            if (!stack.length || cnt >= k) break ;
            if (stack[stack.length - 1] >= num) break ;
            stack.pop();
            cnt++;
        }
        stack.push(num);
    }
    return stack.join('').slice(0, stack.length - (k-cnt));
}

// function solution(number, k) {
//     const max = number.slice(0, k + 1).split('').sort((a, b) => b - a)[0];
//     const idx = number.indexOf(max)
//     let answer = number.slice(idx);
    
//     k -= idx;
//     if (!k) return answer;
//     for (let i = 1; i < answer.length - 1; i++) {
//         if (k && answer[i] < answer[i + 1]) {
//             answer = answer.slice(0, i) + answer.slice(i + 1);
//             k--;
//         }
//         if (!k) break ;
//     }
//     return k ? answer.slice(0, answer.length - k) : answer;
// }