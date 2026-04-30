#include <bits/stdc++.h>
using namespace std;

const int sz = 1e7 + 5;

bool isPrime[sz];
vector<int> primes;

void sieve()
{
    for (int i = 2; i < sz; ++i)
    {
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i < sz; ++i)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j < sz; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i < sz; ++i)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
        }
    }
}