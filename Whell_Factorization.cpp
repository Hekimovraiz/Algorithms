/// Author: Raiz
#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> wheel(int n)
{
    vector<int> res;
    for (int i = 2; i <= 5; ++i)
    {
        while(n % i == 0)
        {
            res.push_back(i);
            n /= i;
        }
    }
    array<int, 8> inc = {4, 2, 4, 2, 4, 6, 2, 6};
    int d = 0;
    for (int i = 7; i * i <= n; i += inc[d++])
    {
        if (d == 8)
        {
            d = 0;
        }
        while(n % i == 0)
        {
            n /= i;
            res.push_back(i);
        }
    }
    if (n > 1)
    {
        res.push_back(n);
    }
    return res;
}
