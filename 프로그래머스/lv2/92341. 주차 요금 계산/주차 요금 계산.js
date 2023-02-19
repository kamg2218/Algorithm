function solution(fees, records) {
    var answer = [];
    const board = new Map();
    const result = new Map();
    const [dTime, dFee, uTime, uFee] = fees;
    
    const getMinutes = (inTime, outTime) => {
        const [inHour, inMinute] = inTime.split(':');
        const [outHour, outMinute] = outTime.split(':');
        const [diffH, diffM] = [Number(outHour) - Number(inHour), Number(outMinute) - Number(inMinute)]
        return diffH * 60 + diffM;
    }
    
    records.forEach(record => {
        const [time, plateNumber, state] = record.split(' ');
        
        if (state === 'IN') {
            board.set(plateNumber, time);
            return ;
        }
        const minutes = getMinutes(board.get(plateNumber), time);
        if (result.has(plateNumber)) {
            result.set(plateNumber, result.get(plateNumber) + minutes);
        } else {
            result.set(plateNumber, minutes);
        }
        board.delete(plateNumber);
    });
    
    board.forEach((v, k) => {
        const tmp = getMinutes(v, "23:59");
        if (result.has(k)) {
            result.set(k, result.get(k) + tmp);
        } else {
            result.set(k, tmp);
        }
    });

    result.forEach((v, k) => {
         const fee = v <= dTime ? dFee : dFee + Math.ceil((v - dTime) / uTime) * uFee;
        result.set(k, fee);
    });
    
    return [...result.keys()].sort().map(v => result.get(v));
}