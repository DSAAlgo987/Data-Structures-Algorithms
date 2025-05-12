#include <stdio.h>
#include <stdlib.h>

int board[20]; // It will store column no at which queen is placed
int count = 0; 

int print(int n){

    printf("\n\nSolution %d:\n\n", ++count);
    int i, j;
    for(i = 1; i<= n;i++){
        printf("\t%d", i);
    }

    for(i = 1; i<= n; i++){
        printf("\n\n%d", i);
        
        for(j = 1; j <= n; j++){
            if(board[i] == j){
                printf("\tQ");
            }else{
                printf("\t-");
            }
        }
    }
}

int place(int row, int col){
    // Check queen can be placed with given row and column 
    int i;

    // Check prev rows from to top to bottom not current row
    for(i = 1; i <= row-1; i++){
        // Check Same column 
        if(board[i] == col){
            return 0; // Conflict
        }

        // Check diagonal 
        if(abs(board[i] - col) == abs(i - row)){
            return 0; // Conflic
        }
    }

    return 1; // No conflict
}

void nQueen(int row, int n){

    int col;
    for(col = 1; col <= n; col++){
        // Is it safe to place queen?
        if(place(row, col)){
            // safe then place queen 
            // We are storing Queen row by row
            board[row] = col;

            // if row reaches the end 
            if(row == n){
                // print configuration board
                print(n);
            }else{
                // Try with new rows
                nQueen(row + 1, n);
            }
        }
    }
}

int main(){
    int n;
    
    printf("Enter no of queens: ");
    scanf("%d", &n);

    nQueen(1, n);

}