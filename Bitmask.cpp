/// Author: Raiz
#include <bits/stdc++.h>
#define int long long
using namespace std;

/// Bitmasking is used to generate all possible subsets of a vector.
/// For each subset, we calculate its sum and keep track of the maximum.
/// This approach has O(2^n * n) complexity and works well for small n.

int Sum_Bitmask(const vector<int> &vec, const int &vec_size)
{
    int Max_Sum = accumulate(vec.begin(), vec.end(), 0);
    for(int mask = 0 ; mask < (1LL << vec_size) ; ++mask)
    {
        int Sum = 0;
        for(int i = 0 ; i < vec_size ; ++i)
        {
            if(mask & (1LL << i))
            {
                Sum += vec[i];
            }
        }
        Max_Sum = max(Max_Sum , Sum);
    }
    return Max_Sum;
}
