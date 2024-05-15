
// let n = parseInt(process.argv[2]); // convert string to int

// let first = 0;
// let second = 1;

// let s = first + " " + second;

// if (n === 0) {
//     console.log([]);
//     return;
// }

// if (n == 1){
//     console.log(s.substring(0,1));
//     return;
// }

// //       first  second  nextNum
// // 3 =>  0      1       1

// let nextNum = first + second; // 1

// for (let i = 3; i <= n; i++) {
//     s = s + " " + nextNum;
//     first = second;
//     second = nextNum;
//     nextNum = first + second;
// }

// if (n >= 2) {
//     console.log(s);
// }


// 0 => []
// 1 => [0]
// 2 => [0 , 1] sequence = 
// 3 => [0 1 1]
// 4 => [0 1 1 2]

let s = "0 1";
let first = 0;
let second = 1;
let nextNum;

let n = parseInt(process.argv[2]);

if(n <=0){
    console.log("Enter a positive number.");
}else if(n === 1 ){
    console.log(s.substring(0 ,1));
}else if (n === 2){
    console.log(s);
}else {
    console.log(fibonacci(4-2));

}

function fibonacci(n){
    if(n > 0){
        nextNum = first +second;
        s = s + " "+nextNum;
        first = second;
        second = nextNum;
        fibonacci(n-1);
    }
    return s;
}



