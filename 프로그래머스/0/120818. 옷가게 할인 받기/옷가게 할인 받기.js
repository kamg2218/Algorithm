function solution(price) {
    const num = 100000;
    if (price >= 5 * num) return parseInt(price * 0.8);
    else if (price >= 3 * num) return parseInt(price * 0.9);
    else if (price >= 1 * num) return parseInt(price * 0.95);
    return price;
}