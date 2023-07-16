function solution(bridge_length, weight, truck_weights) {
    let answer = 0;
    let [start, end, sum] = [0, 0, 0];
    const onBridge = [];
    
    while (start < truck_weights.length || onBridge.length) {
        answer++;
        while (onBridge.length && answer - onBridge[0] === bridge_length) {
            onBridge.shift();
            sum -= truck_weights[start++];
        }
        if (sum + truck_weights[end] <= weight) {
            onBridge.push(answer);
            sum += truck_weights[end++];
        }
    }
    return answer;
}