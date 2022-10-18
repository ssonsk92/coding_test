function solution(seoul) {
    var answer = '';

    for(let i = 0; i < seoul.length; ++i){
        const name = seoul[i];
        if(name === "Kim"){
            return `김서방은 ${i}에 있다`;
        }
    }

    return answer;
}

console.log(solution(["Jane", "Kim"]));