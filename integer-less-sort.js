function solution(n) {
    let answer = 0;
    let arr = [];
    while(0 < n){
        arr.push(n % 10);
        n = parseInt(n / 10);
    }
    
    arr = arr.sort(function(a, b){
        return b-a;
    });
    
    for(i = 0; i < arr.length; ++i)
        answer = answer * 10 + arr[i]
    
    return answer;
}