function tree(n){
    if(n > 0 ){
        console.log(n);
        debugger
        tree(n-1); // Recursive call

        tree(n-1); // Recursive call
    }
}

tree(3);

// Tree recursion : When a recursive function is called more than one time this recursive function is called "Tree Recursion".

// output : 3 , 2 , 1 , 1 , 2 , 1 , 1

