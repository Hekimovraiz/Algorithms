/// Author: Raiz
#include <bits/stdc++.h>
#define int long long
using namespace std;

/// 1. Classic Binary Search (check if element exists)
bool Binary_Search(vector<int> &vec, const int &vec_size, const int &target)
{
    sort(vec.begin(), vec.end());
    int l = 0, r = vec_size - 1, mid, best = 0;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (vec[mid] >= target)
        {
            best = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return vec[best] == target;
}

/// 2. Generic Binary Search (find first index where check = true)
/// This is used for optimization / answer searching problems
int Binary_Search(vector<int> &vec, const int &vec_size)
{
    int l = 0, r = vec_size - 1, mid, best = 0;
    auto check = [&](int mid)
    {
        /// Write your condition here
        return true;
    };

    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (check(mid))
        {
            best = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
}