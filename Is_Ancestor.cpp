/// Author: Raiz
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int sz = 1e5 + 7;
vector<int> adj[sz];
int tin[sz], tout[sz], timer;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    for (int u : adj[v])
    {
        if (u != p)
            dfs(u, v);
    }
    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

