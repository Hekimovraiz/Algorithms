/// Author: Raiz
#include <bits/stdc++.h>
using namespace std;

const int sz = 2e5 + 31;
const int INF = 1e18;
int n, qr;
int a[sz], t[sz << 2], lazy[sz << 2];

struct Lazy_Segment_Tree
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
        t[node] = min(t[node << 1], t[node << 1 | 1]);
    }

    void push(int node, int l, int r)
    {
        if (lazy[node] != 0)
        {
            t[node] += lazy[node];
            if (l != r)
            {
                lazy[node << 1] += lazy[node];
                lazy[node << 1 | 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    int get(int node, int l, int r, int ql, int qr)
    {
        push(node, l, r);
        if (r < ql || l > qr)
        {
            return INF;
        }
        if (l >= ql && r <= qr)
        {
            return t[node];
        }
        int mid = (l + r) >> 1;
        return min(get(node << 1, l, mid, ql, qr), get(node << 1 | 1, mid + 1, r, ql, qr));
    }

    void update(int node, int l, int r, int ql, int qr, int val)
    {
        push(node, l, r);
        if (r < ql || l > qr)
        {
            // exit(0);
            return;
        }
        if (l >= ql && r <= qr)
        {
            lazy[node] += val;
            push(node, l, r);
            return;
        }
        int mid = (l + r) >> 1;
        update(node << 1, l, mid, ql, qr, val);
        update(node << 1 | 1, mid + 1, r, ql, qr, val);
        t[node] = min(t[node << 1], t[node << 1 | 1]);
    }
};