
let n = 12345;
let answer = [];

while (0 < n) {
    const value = n % 10;
    answer.push(value);
    n = parseInt(n / 10);
}

console.log(answer);

