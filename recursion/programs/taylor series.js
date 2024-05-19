let s =1;

function e(x , n){
    while(n > 0){
        s = 1 + x/n *s;
        e(x , n-1);
        return s;
    }
    return s;
}

console.log(e(1, 4).toFixed(2));
