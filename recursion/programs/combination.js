function fact(n){
    if(n===0) return 1;
    return fact(n-1) *n;
}

function nCr(n , r){
    let num = fact(n);
    let den = fact(r) * fact(n-r);

    return num/den;
}

// function c(n, r) {
//     if (r === 0 || n === r) {
//         return 1;
//     } else {
//         return c(n - 1, r - 1) + c(n - 1, r);
//     }
// }

console.log(nCr(5 , 3));