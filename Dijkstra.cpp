/// Author: Raiz
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
const int sz = 1e5 + 7;

int n, m;
vector<pair<int, int>> v[sz];
vector<int> dp(sz, INF), parent(sz);

void DIJKSTRA(int node)
{
    multiset<pair<int, int>> st; // cost , node
    dp[node] = 0;
    st.insert({0, node});
    while (!st.empty())
    {
        auto f = *st.begin();
        st.erase(f);
        for (auto to : v[f.second])
        {
            if (dp[to.first] > dp[f.second] + to.second)
            {
                parent[to.first] = f.second;
                dp[to.first] = dp[f.second] + to.second;
                st.insert({dp[to.first], to.first});
            }
        }
    }
}
