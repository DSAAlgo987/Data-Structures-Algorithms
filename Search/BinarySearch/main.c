//Binary Search
#include <stdio.h>

int binarySearch(int *a,int size,int element)
{
    int low,high,mid;
    low=0;
    high=size-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==element)
        {
            return mid;
        }
        if(a[mid]<element)
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}

int main()
{
    int a[]={3,4,53,56,234,3452,23413};
    int size=7;
    int element=234;
    int searchIndex=binarySearch(a,size,element);
    
    printf("%d Element found at %d index",element,searchIndex);

    return 0;
}

