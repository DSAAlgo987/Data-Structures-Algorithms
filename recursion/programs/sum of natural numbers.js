// let sum = 0 ;
// for(let i = 1 ; i <= 2 ; i++ ){
//     sum+= i;
// }

// console.log(sum);

// 2 = 1+2 
// 3 = 1+ 2 + 3

function sumOfN(n){
    if(n > 0){
        return sumOfN(n-1) + n;
    }

    return 0;
}

console.log(sumOfN(3));

// Time complexity : O(n);
// space complexity : o(n);