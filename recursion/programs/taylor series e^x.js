// Taylor series e^x

// e^x = 1 + x^1 / !1 + x^2 / !2 + x^3 / !3 + x^4 / !4 -- n terms

let p = 1; // power
let f = 1; // factorial
let result;

function e(x , n){
    if(n === 0 ){
        return 1;
    }else{
        result = e(x , n-1);
        p = p * x;  
        f = f * n;
        return result + p/f;
    }
}

console.log(e(1, 4).toFixed(2));