
#include <stdio.h>
#define SIZE 10

int hash(int key){
    return key % 10;
}

int prob(int HT[] , int key){
    int index = hash(key);
    
    int i = 0 ; 
    while(HT[(index + i)  % SIZE] != 0){
        i++;
    }
    
    return (index + i) % SIZE;
}

void Insert(int HT[] ,int key){
    int index = hash(key);
    
    // already occupied
    if(HT[index] != 0){
        index = prob(HT , key);
    }
    
    HT[index]=key;
}

int Search(int HT[]  , int key){
    int index = hash(key);
    
    int i = 0;
     // Linear probing to find the key
    while(HT[(index + i) % SIZE] != 0){
        if(HT[(index + i) % SIZE] == key){
            return (index + i) % SIZE; // Return the index if found
        }
        i++;
    }
    
    return -1; // Return -1 if the key is not found
}

void display(int HT[]){
    int i;
    for( i = 0 ; i < SIZE ; i++){
        // only occupied elements will be displayed 
        if(HT[i] != 0 ){
            printf(" %d " , HT[i]);
        }
    }
}


int main()
{
    int HT[10] = {0};

    Insert(HT , 20);
    Insert(HT , 23);
    Insert(HT , 40);
    Insert(HT , 25);
    Insert(HT , 30);
    
    display(HT);
    
      // Searching for keys
    printf("\nSearch 20: %d\n", Search(HT, 20)); // Should return the index where 20 is stored
    printf("Search 25: %d\n", Search(HT, 25)); // Should return the index where 25 is stored
    printf("Search 50: %d\n", Search(HT, 50)); // Should return -1 (not found)


    return 0;
}
