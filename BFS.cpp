/// Author: Raiz
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int sz = 1e5 + 7;
vector<int> adj[sz];
int dp[sz];
bool visited[sz];

void BFS(int start_node)
{
    queue<int> q;
    q.push(start_node);
    visited[start_node] = true;
    dp[start_node] = 0;

    while (!q.empty())
    {
        int f = q.front();
        q.pop();

        for (auto to : adj[f])
        {
            if (!visited[to])
            {
                visited[to] = true;
                dp[to] = dp[f] + 1;
                q.push(to);
            }
        }
    }
}
