#include <stdio.h>
#include <string.h>


void subset(char *str, int index, char *substrs, int currentLen){

    // Base case 
    if(str[index] == '\0'){
        substrs[currentLen] = '\0';
        printf("%s\n", substrs);
        
        return;
    }

    substrs[currentLen] = str[index];
        
    // Include current char
    subset(str, index+1, substrs, currentLen+1);
    
    // Exclude current char 
    subset(str, index+1, substrs, currentLen);
    
    
}

int main()
{
    char substrs[100];
    subset("ab", 0, substrs, 0);

    return 0;
}