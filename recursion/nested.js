function nested(n){     // T(n);
    if(n > 100){        // 1
        return n-10;    // 1
    }else {
        return nested(nested(n+11)); // recursive call // T(T(n+11))
    }
}

console.log(nested(95));

// Definition : If a recursive function is passed as a parameter in a recursive call then it is called as "Nested Recursion".

// Time Complexity : O(n) Bcoz it is linear.

// Space Complexity : O(n)

// output : 91
