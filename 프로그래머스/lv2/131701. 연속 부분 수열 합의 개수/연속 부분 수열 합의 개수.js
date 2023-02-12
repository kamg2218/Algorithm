function solution(elements) {
    const result = new Set(elements);
    const len = elements.length;

    elements.forEach((element, idx) => {
        let sum = 0;
        for (let i = 1; i <= len; i++) {
            sum += elements[(idx + i) % len];
            result.add(sum);
        }
    });
    return result.size;
}