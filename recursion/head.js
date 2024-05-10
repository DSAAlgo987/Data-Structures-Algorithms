function recursive(n){
    if(n > 0){
        recursive(n-1);
        console.log(n);
    }
}

let x = 3;
recursive(x); 

// output : 3  2 1 