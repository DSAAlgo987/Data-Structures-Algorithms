//Linear Search 
#include <stdio.h>

int linearSearch(int *a,int size,int element)
{
    for(int i=0;i<size;i++)
    {
        if(a[i]==element)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int a[]={1,431,2,12,4,12,24};
    int size=7;
    int element =12;
    int searchIndex=linearSearch(a,size,element);
    printf("The %d element at %d",element,searchIndex);

    return 0;
}

