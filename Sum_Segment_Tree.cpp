/// Author: Raiz
#include <bits/stdc++.h>

const int sz = 2e5 + 31;
int a[sz], t[sz << 2];

struct Segmnet_Tree
{
    void build(int node, int l, int r)
    {
        if (l == r)
        {
            t[node] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(node << 1, l, mid);
        build(node << 1 | 1, mid + 1, r);
        t[node] = t[node << 1] + t[node << 1 | 1];
    }

    int get(int node, int l, int r, int ql, int qr)
    {
        if (l > qr || r < ql)
        {
            return 0;
        }
        if (r <= qr && l >= ql)
        {
            return t[node];
        }
        int mid = (l + r) >> 1;
        return get(node << 1, l, mid, ql, qr) + get(node << 1 | 1, mid + 1, r, ql, qr);
    }

    void update(int node, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            t[node] = val;
            return;
        }
        int mid = (l + r) >> 1;

        if (pos <= mid)
        {
            update(node << 1, l, mid, pos, val);
        }
        else
        {
            update(node << 1 | 1, mid + 1, r, pos, val);
        }
        t[node] = t[node << 1] + t[node << 1 | 1];
    }
};
