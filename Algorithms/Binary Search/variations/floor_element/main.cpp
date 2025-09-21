#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Statement: Find floor of an element in a sorted array.
 *
 * If that element then return that element.
 * If not then:
 * Floor of an element = Smaller greater element then that element.
 *
 * Ip:
 * vector<int> arr, int Ele;
 *
 * Op:
 * return index of that element
 */

int BinarySearchFloor(vector<int> &arr, int ele)
{
    int start = 0;
    int end = arr.size() - 1;
    int res = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == ele)
        {
            res = mid; // Possible floor
            start = mid + 1;
        }
        else if (arr[mid] <= ele)
        {
            res = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return res;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 7, 8, 10};

    cout << BinarySearchFloor(arr, 5) << endl; // op: 4
    return 0;
}