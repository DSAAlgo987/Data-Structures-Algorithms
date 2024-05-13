// let base = 2;
// let exponent = 3;

// let power = 1;
// for(let i = 1 ; i <=exponent ; i++){
//     power *= base;
// }

// console.log(power);

// 2 ^ 3 = 2 -> base & 3 -> exponent 
// 2 * 2 * 2
// power = 1;
// power * = base;
// 1 * 2 = 2
// 2 * 2 = 4
// 4 * 2 = 8

// 0 -> 1


function power(exponent  , base){
    if(exponent > 0 ){
        return power(exponent - 1 , base) * base;
    }
    return 1;
}

console.log(power(3 , 2));

// 3 , 2
// power(3 , base) -> 4 * 2 = 8
// power(2 , base) -> 2 * 2 = 4
// power(1 , base) -> 1 * 2 = 2
// power(0 , base) -> 1