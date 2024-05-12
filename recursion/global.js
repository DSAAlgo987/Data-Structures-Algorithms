// Local variable.
// function recursive(n){
//     if(n > 0){
//         return recursive(n-1) * n;
//     }

//     return 1;
// }

// console.log(recursive(3));

// Global variable
let x = 0;

function recursive(n){
    if(n > 0){
        ++x;
        return recursive(n-1) * x;
    }

    return 1;
}
console.log(recursive(3));
