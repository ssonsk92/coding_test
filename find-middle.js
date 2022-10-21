function solution(s) {
    const isEven = (s.length % 2) === 0;
    const mid = parseInt(s.length / 2);
    if(isEven){
        return s.substring(mid - 1, mid + 1);
    }else{
        return s.substring(mid, mid + 1);
    }
}

console.log(solution("qwer"));