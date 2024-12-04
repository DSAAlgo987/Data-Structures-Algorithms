
#include <stdio.h>
#define SIZE 10

int hash(int key){
    return key %10;
}

int prob(int HT[] , int key){
    int index = hash(key);
    int i = 0;
    while(HT[(index + i^2) % SIZE] != 0){
        i++;
    }
    
    return (index + i^2)%SIZE;
}

int Insert(int HT[] , int key){
    int index = hash(key);
    
    // already occupied
    if(HT[index]!= 0){
        index = prob(HT , key);
    }
    
    HT[index] = key;
}

int Search(int HT[] , int key){
    int index = hash(key);
    int i = 0;
    // blanck space nhi huna chahiye
    while(HT[(index + i^2) % SIZE] != 0){
        while(HT[(index + i^2) % SIZE] != key){
            return (index + i^2) % SIZE;  
        }         
        i++;
    }
    
    return -1;
}

void display(int HT[]){
    int i;
    for(i = 0 ; i < SIZE ; i++){
        if(HT[i]!= 0){
            printf("HT[%d] -> %d \n",i , HT[i]);   
        }
    }
}

int main()
{
    int HT[10] = {0};
    
    Insert(HT , 23);
    Insert(HT , 43);
    Insert(HT , 13);
    Insert(HT , 27);
    
    display(HT);
       // Searching for keys
    printf("\nSearch 20: %d\n", Search(HT, 20)); // Should return the index where 20 is stored
    printf("Search 23: %d\n", Search(HT, 23)); // Should return the index where 25 is stored
    printf("Search 50: %d\n", Search(HT, 50)); // Should return -1 (not found)

    return 0;
}
