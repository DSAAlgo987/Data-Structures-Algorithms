#include <stdio.h>
#define SIZE 10

int hash(int key){
    return key % SIZE;
}

int probe(int H[] , int key){
    int index = hash(key);
    int i = 0; 
    while(H[(index + i)%SIZE]!=0){
        i++;
    }
    return (index + i) %SIZE;
}

void Insert(int H[],int key){
    int index = hash(key);

    // already occupied
    if(H[index] != 0){
        index = probe(H , key);        
    }
    H[index] = key;
}


int main(){
    int HT[SIZE] = {0};

    Insert(HT , 22);
    Insert(HT , 42);
    Insert(HT , 33);

    return 0;
}