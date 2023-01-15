function solution(brown, yellow) {
    const large = brown + yellow;

    let y = 3;
    while (true) {
        if (large % y) {
            y++;
            continue ;
        }
        const quote = large / y;
        if (((y - 2) * (quote - 2)) === yellow) {
            return [quote, y];
        }
        y++;
        if (quote < y) {
            break ;
        }
    }
}