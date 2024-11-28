#include <stdio.h>
#include <conio.h>

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

int partition(int a[], int l, int h)
{
    int povit = a[l]; //first element as pivot
    int i = l, j = h;

    do
    {
        do
        {
            i++;
        } while (a[i] <= povit);
        do
        {
            j--;
        } while (a[j] > povit);

        if (i < j) // i should be less than j
        {
            swap(&a[i], &a[j]);
        }

    } while (i < j);

    swap(&a[l], &a[j]); // swap pivot with jth element

    return j; // partitioning position
}

void QuickSort(int a[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(a, l, h); // here j was missing
        QuickSort(a, l, j);
        QuickSort(a, j + 1, h);
    }
}

int main()
{
    int a[100], n, i;
    printf("\n ENter size of array");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf(" ENter a[%d]", i);
        scanf("%d", &a[i]);
    }

    printf("\n Elements before sorting\n");

    for (i = 0; i < n; i++)
    {
        printf(" %d", a[i]);
    }

    QuickSort(a, 0, n);

    printf("\n Elements after sorting\n");

    for (i = 0; i < n; i++)
    {
        printf(" %d", a[i]);
    }
}