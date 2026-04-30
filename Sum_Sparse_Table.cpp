/// Author: Raiz
#include <bits/stdc++.h>
using namespace std;

const int sz = 1e5 + 1;
const int LOG = 20;

int n;
int st[LOG][sz], a[sz];

struct Sparse_Table
{
    void build()
    {
        for (int i = 0; i < n; ++i)
        {
            st[0][i] = a[i];
        }

        for (int j = 1; j < LOG; ++j)
        {
            for (int i = 0; i + (1ll << j) - 1 < n; ++i)
            {
                st[j][i] = st[j - 1][i] + st[j - 1][i + (1ll << (j - 1))];
            }
        }
    }

    int get(int l, int r)
    {
        int sum = 0;
        for (int j = LOG - 1; j >= 0; --j)
        {
            if ((1LL << j) <= r - l + 1)
            {
                sum += st[j][l];
                l += (1LL << j);
            }
        }
        return sum;
    }
};
