function solution(s){
    var answer = true;

    let pCount = 0, yCount = 0;
    for(let i = 0; i < s.length; ++i){
        const c = s[i];
        if('p' == c || 'P' == c){
            pCount++;
        }
        
        if('y' == c || 'Y' == c){
            yCount++;
        }
        
    }
    
    return pCount == yCount;
}