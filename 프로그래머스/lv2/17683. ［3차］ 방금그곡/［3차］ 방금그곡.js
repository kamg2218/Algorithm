const melodies = {
    'C':'0',
    'C#':'1',
    'D':'2',
    'D#':'3',
    'E':'4',
    'F':'5',
    'F#':'6',
    'G':'7',
    'G#':'8',
    'A':'9',
    'A#':'a',
    'B':'b',
}

function solution(m, musicinfos) {
    const answer = {name: '', time: 0};
    const convertedM = convertMelody(m);
    
    for (const music of musicinfos) {
        const splitedMusic = music.split(',');
        const time = getTime(splitedMusic[0], splitedMusic[1]);
        const convertedMelody = convertMelody(splitedMusic[3]);
        const len = convertedMelody.length;
        const melody = convertedMelody.repeat(Math.ceil(time / len)).slice(0, time);
        if (melody.search(convertedM) !== -1 && time > answer.time) {
            answer.name = splitedMusic[2];
            answer.time = time;
        }
    }
    return answer.name === '' ? '(None)' : answer.name;
}

const getTime = (start, end) => {
    const splitedStart = start.split(':').map(Number);
    const splitedEnd = end.split(':').map(Number);
    
    return (splitedEnd[0] - splitedStart[0]) * 60 + (splitedEnd[1] - splitedStart[1]);
}

const convertMelody = (melody) => {
    const result = [];
    for (let i = 0; i < melody.length; i++) {
        if (melody[i + 1] === '#') {
            result.push(melodies[melody[i] + '#']);
            i++;
        } else {
            result.push(melodies[melody[i]]);
        }
    }
    return result.join('');
}