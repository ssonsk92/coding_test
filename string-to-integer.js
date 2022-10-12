function solution(s) {
    let answer = 0;
    let sign = 1;
    for(let idx = 0; idx < s.length; ++idx){
        const c = s[idx];
        if(c == "+"){
            continue;
        }

        if(c == "-"){
            sign = -1;
            continue;
        }
        
        answer = answer * 10 + parseInt(s[idx]);
    }

    return sign * answer;
}

console.log(solution("-1234"));