function recursive(n){
    if(n>0){
        console.log(n);

        recursive(n-1); // linear recursion

        console.log(n);
    }
}

// Linear Recursion : It is a function which is called after some process and before some process is called linear recursion. Which is called only one time.

recursive(3);