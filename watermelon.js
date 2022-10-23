function solution(n) {
    var answer = '';
    const isOdd = (n % 2) !== 0;
    const str = "수박";
    const strCount = parseInt(n / 2);
    console.log(strCount);
    for(let cnt = 0; cnt < strCount; ++cnt){
        answer += str;
    }

    if(isOdd){
        answer += str.at(0);
    }

    return answer;
}

console.log(solution(1));