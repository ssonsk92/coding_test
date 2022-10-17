function solution(a, b) {
    var answer = 0;

    const min = Math.min(a, b);
    const max = Math.max(a, b);

    for(let value = min; value <= max; ++value){
        answer += value;
    }

    return answer;
}

console.log(solution(3, 3));