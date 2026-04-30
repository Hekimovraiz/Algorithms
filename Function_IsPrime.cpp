/// Author: Raiz
#include <bits/stdc++.h>
using namespace std;

bool isPrime(const int &n)
{
    if(n < 2)
    {
        return false;
    }
    if(n == 2 || n == 3)
    {
        return true;
    }
    if(n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }
    for(int i = 5 ; i * i <= n ; ++i)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

