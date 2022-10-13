function solution(x, n) {
    var answer = [];
    
    for(let idx = 0, value = x; idx < n; ++idx, value += x){
        answer.push(value);
    }

    return answer;
}

console.log(solution(2, 5));