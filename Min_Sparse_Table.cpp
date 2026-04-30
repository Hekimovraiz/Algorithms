/// Author: Raiz
#include <bits/stdc++.h>
using namespace std;

const int sz = 1e5;
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
                st[j][i] = min(st[j - 1][i], st[j - 1][i + (1ll << (j - 1))]);
            }
        }
    }

    int get(const int &l, const int &r)
    {
        int LG = (int)log2(r - l + 1);
        return min(st[LG][l], st[LG][r - (1ll << LG) + 1]);
    }
};
