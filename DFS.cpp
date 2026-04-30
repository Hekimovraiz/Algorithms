/// Author: Raiz
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int sz = 1e5 + 7;

vector<int> a[sz];
bool visited[sz];

void DFS(int node)
{
    visited[node] = true;
    for (auto to : a[node])
    {
        if (!visited[to])
        {
            DFS(to);
        }
    }
}

