function factorial(n){
    if( n > 0){
        return factorial(n-1) * n;
    }
    return 1;
}

console.log(factorial(3)); // 6

