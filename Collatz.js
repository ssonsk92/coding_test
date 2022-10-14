function solution(num) {
    var answer = 0;

    if(1 == num){
        return 0;
    }

    while(answer++ < 500){
        if(0 === (num % 2)){
            num = num / 2;
        }
        else{
            num = num * 3 + 1;
        }

        if(1 === num){
            break;
        }
    }

    if(500 <= answer){
        return -1;
    }

    return answer;
}

console.log(solution(8000000));