/// Author: Raiz
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int sz = 1e3;
int n, a[sz], ft[sz];

struct Fenwick_Tree
{
    void update(int idx, int val)
    {
        while (idx <= n)
        {
            ft[idx] += val;
            idx += idx & -idx;
        }
    }

    int calc(int idx)
    {
        int res = 0;
        while (idx > 0)
        {
            res += ft[idx];
            idx -= idx & -idx;
        }
        return res;
    }
};