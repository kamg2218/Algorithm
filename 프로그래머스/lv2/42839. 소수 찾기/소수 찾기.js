function getCombination(elements, pick) {
    if(pick === 1) return elements.map(elem => [elem]);
    
    const combinations = [];
    elements.forEach((element, index) => {
        const smallerCombinations = getCombination(elements.slice(index + 1), pick - 1);
        smallerCombinations.forEach(combination => {
            combinations.push([element].concat(combination));
        });
    });
    return combinations;
}

function getPermutation(elements) {
    if(elements.length === 1) return [elements];
    const permutations = [];
    
    const smallerPermutations = getPermutation(elements.slice(1));

    const fisrtElement = elements[0];
    smallerPermutations.forEach(permutation => {
        for(let positionIndex = 0; positionIndex <= permutation.length; positionIndex++) {
            const prefix = permutation.slice(0, positionIndex);
            const suffix = permutation.slice(positionIndex);
            permutations.push(prefix.concat([fisrtElement], suffix));
        }
    });
    return permutations;
}

const primeNumber = (num) => {
    if (num <= 1) return false;
    for (let i = 2; i <= Math.sqrt(num); i++) {
        if (num % i === 0) return false;
    }
    return true;
}

function solution(numbers) {
    let cnt = 0;
    const num = new Set();

    for (let i = 0; i < numbers.length; i++) {
        const result = getCombination(numbers.split(''), i + 1);
        result.forEach(value => {
            getPermutation(value).forEach(v => num.add(parseInt(v.join(''))))
        });
    }
    
    num.forEach(n => {
        if (primeNumber(n)) cnt++;
    })
    
    return cnt;
}