function solution(elements) {
    const result = new Set();
    const len = elements.length;
    
    elements.forEach((element, idx) => {
        for (let i = 0; i < len; i++) {
            let sum = 0;
            for (let j = i; j < i + idx + 1; j++) {
                sum += (j >= len ? elements[j - len] : elements[j]);
            }
            result.add(sum);
        }
    })
    return result.size;
}