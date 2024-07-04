function foo(n, sum) {
    let k = 0, j = 0;
    if (n === 0) return;

    k = n % 10;
    j = parseInt(n / 10);
    sum = sum + k;
    foo(j, sum);
    console.log(k);
}

let a = 2048, sum = 0;
foo(a, sum);

console.log(sum);