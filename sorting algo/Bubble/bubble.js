function bubbleSort(a) {
    let temp;
    for (let i = 0; i < a.length - 1; i++) {
        for (let j = i + 1; j < a.length - 1; j++) {
            if (a[j] > a[i]) {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
    return a;
}

let a = [20 , 30 ,1 , 2  , 4];
console.log(bubbleSort(a));