function solution(arr) {
    let minNumber = arr[0];

    arr.forEach(element => {
        if(element < minNumber){
            minNumber = element;
        }
    });

    arr = arr.filter((number)=>{
        return minNumber < number;
    });

    if (arr.length === 0) {
        return [-1];
    }

    return arr;
}

console.log(solution([3, -4, 4,-2,1]));