// Types of Recursion : 

// 1. Tail Recursion 
// 2. Head Recursion 
// 3. Tree Recursion 
// 4. Indirect Recursion
// 5. Nested Recursion

// function tail(n){ // recursive function 
//     if(n > 0 ){
//         console.log(n); // 

//         tail(n-1); // recursive call 
//     }
// }


// tail : when a recursive function call itself and that recursive call is the last statement , then it is called as "Tail Recursion".

// Time complexity : O(n);
// Space complexity : O(n);

// tail(3);
// output : 3 2 1 

// function head(n){
//     if(n > 0 ){
//         head(n-1);
//         console.log(n);

//     }
// }
// head(3);

// output : 1 2 3

// Head recursion  : it is a function that doesn't have to perform any operation & process at the time of calling. It has to do all the operations and process at the time of returning so these functions are called "Head recursions";

// Time complexity : O(n);
// Space complexity : O(n);

// Recursion vs loop 
// Recursion : Ascending and descending
// Loop : Ascending


// function factorial(n){
//     let fact = 1;
//     for(let i = 1 ; i<=n ; i++){
//         fact *= i;
//     }

//     return fact;
// }

// console.log(factorial(3));


function factorial(n){
    if(n  >  0){
        return factorial(n-1) * n;
    }

    return 1;
}
console.log(factorial(3));
