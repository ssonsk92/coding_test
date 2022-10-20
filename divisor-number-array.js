function solution(arr, divisor) {
    var answer = [];
    arr.sort((a, b)=> {return a-b;});
    
    for(let i = 0; i < arr.length; ++i){
        const num = arr[i];
        if(0 === num % divisor){
            answer.push(num);
        }
    }

    if(answer.length === 0){
        return [-1];
    }

    return answer;
}

console.log(solution([5, 9, 7, 10], 5));