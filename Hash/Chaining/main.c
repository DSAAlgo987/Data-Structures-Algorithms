#include <stdio.h>
#include "chains.h"

int hashCode(int key){
    return key % 10;
}

void insert(struct Node *H[], int key) {
    int index = hashCode(key);
    H[index] = insertNodeSortLL(&H[index], key);
}
int main(){
    struct Node *HT[10];

    // Initialize HT indices as NULL
    for(int i = 0 ; i < 10 ; i++){
        HT[i] = NULL;
    }
    insert(HT , 22);
    insert(HT , 12);
    insert(HT , 32);


    searchElement(HT[hashCode(30)] , 30);
    return 0;
}