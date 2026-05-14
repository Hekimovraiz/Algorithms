/// Author: Raiz
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<int> dp;

void LIS(const vector<int> &vec, const int &vec_size)
{
    for (int i = 0; i < vec_size; ++i)
    {
        auto it = lower_bound(dp.begin(), dp.end(), vec[i]);
        if (it == dp.end())
        {
            dp.push_back(vec[i]);
        }
        else
        {
            *it = vec[i];
        }
    }
    cout << (int)dp.size() << "\n";
}