function solution(cacheSize, cities) {
    let answer = 0;
    let cache = [];
    
    if (cacheSize === 0) {
        return cities.length * 5;
    }
    cities.forEach(city => {
        if (cache.includes(city.toLowerCase())) {
            answer += 1;
            cache = cache.filter(c => c !== city.toLowerCase());
        } else {
            answer += 5;
        }
        if (cache.length >= cacheSize) {
            cache.shift();
        }
        cache.push(city.toLowerCase());
    })
    return answer;
}