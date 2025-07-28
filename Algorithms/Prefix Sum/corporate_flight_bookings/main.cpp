#include <bits/stdc++.h>
using namespace std;

// Brute force -> n^2
vector<int> coporateFlightBookingsBruteForce(vector<vector<int>> &bookings, int n)
{
    vector<int> ans(n, 0); // same size as n & initilize with 0

    // Traverse bookings vector
    for (int i = 0; i < bookings.size(); i++)
    {
        int first = bookings[i][0];
        int last = bookings[i][1];
        int seats = bookings[i][2];

        // Start calculating seats for each flights
        for (int j = first - 1; j < last; j++)
        {
            ans[j] += seats;
        }
    }

    return ans;
}

// Optimized -> (booking.size() + n)
vector<int> coporateFlightBookings(vector<vector<int>> &bookings, int n)
{
    vector<int> da(n, 0); // difference array

    // start difference array technique on bookings
    for (auto b : bookings)
    {
        int first = b[0];
        int last = b[1];
        int seats = b[2];

        // add
        da[first - 1] += seats;

        // out of bound
        if (last < n)
        {
            da[last] -= seats;
        }
    }

    // After that apply prefix sum on da
    for (int i = 1; i < n; i++)
    {
        da[i] = da[i - 1] + da[i];
    }

    return da;
}

int main()
{
    vector<vector<int>> bookings = {{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};
    int n = 5;

    for (auto a : coporateFlightBookings(bookings, n))
    {
        cout << a << " ";
    }

    return 0;
}