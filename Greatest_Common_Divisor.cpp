/// Author: Raiz
#include <bits/stdc++.h>
#define int long long
using namespace std;

/// V-1
int __gcd1(int a , int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

/// V-2
int __gcd2(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}