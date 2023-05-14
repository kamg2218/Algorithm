function solution(ingredient) {
    var answer = 0;
    
    for (let i = 0; i < ingredient.length - 3; i++) {
       if (ingredient[i] === 1 && ingredient[i + 1] === 2
          && ingredient[i + 2] === 3 && ingredient[i + 3] === 1) {
            answer++;
            ingredient.splice(i, 4);
            i -= 4;
        }
    }
    return answer;
}