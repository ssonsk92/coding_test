function solution(phone_number) {
    let answer = "";
    const last_idx = phone_number.length - 4;  
    for(let idx = 0; idx < last_idx; ++idx){
        answer += "*";
    }

    answer += phone_number.substring(last_idx);

    return answer;
}

console.log(solution("01033334444"));