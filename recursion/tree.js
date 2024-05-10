function tree(n){
    if(n > 0 ){
        console.log(n);
        debugger
        tree(n-1);

        tree(n-1);
    }
}

tree(3);

// output : 3 , 2 , 1 , 1 , 2 , 1 , 1

