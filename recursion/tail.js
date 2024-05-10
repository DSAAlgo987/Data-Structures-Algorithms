function recursive(n){
    if(n > 0){
        console.log(n);
        recursive(n-1);
    }
}

let x = 3;
recursive(x); 

// output : 3  2 1 