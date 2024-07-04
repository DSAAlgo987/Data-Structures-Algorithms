function TOH(n, A, B, C) {
    if (n > 0) {
        TOH(n-1, A, C, B);
        console.log("From " + A + " to " + C);
        TOH(n-1 , B , A , C);
    }
}


TOH(parseInt(process.argv[2]) , 1 , 2 , 3);