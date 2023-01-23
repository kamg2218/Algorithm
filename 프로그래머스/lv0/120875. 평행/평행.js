function solution(dots) {
    const getSlope = (a, b) => {
        return Math.abs(a[0] - b[0]) / Math.abs(a[1] - b[1]);
    }
    
    for (let i = 1; i < dots.length; i++) {
        const tmp = dots.slice(1, i).concat(dots.slice(i + 1));
        if (getSlope(dots[0], dots[i]) === getSlope(tmp[0], tmp[1])) {
            return 1;
        }
    }
    return 0;
}