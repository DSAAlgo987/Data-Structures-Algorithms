function A(n){
    if(n > 0){
        console.log(n);

        B(n-1);
    }
}

function B(n){
    if(n > 0){
        console.log(n);
        A(parseInt(n/2));
    }
}

A(20);
//20 19 9 8 4 3 1