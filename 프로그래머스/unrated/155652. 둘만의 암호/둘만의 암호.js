// function solution(s, skip, index) {
//     const str = 'abcdefghijklmnopqrstuvwxyz';
//     const splitedStr = str.split('');

//     return s.split('').map(c => {
//         const idx = str.indexOf(c);
//         let num = idx;
//         for (let i = 0; i < index; i++) {
//             num++;
//             if (skip.includes(splitedStr[num % str.length])) {
//                 i--;
//             }
//         }
//         return splitedStr[num % str.length];
//     }).join('');    
// }

function solution(s, skip, index) {

const ALPAHBET = 'abcdefghijklmnopqrstuvwxyz'

let result = []
for(let i = 0; s.length-1 >= i; i++){
    console.log(i, s[i]);
    const answer = [];
    const findIndex = ALPAHBET.indexOf(s[i]);
    const num = index;
    for(let j = findIndex + 1; ALPAHBET.length>=j; j++){
        console.log(j, ALPAHBET[j]);
        
        if(j === 26) j = 0;
        if(num === answer.length) break;
        if(skip.includes(ALPAHBET[j])) continue;
        answer.push(ALPAHBET[j])
    }
    console.log(answer)
    result.push(answer.pop())
}
return result.join("");
}