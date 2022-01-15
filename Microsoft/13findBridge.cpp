#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, vis, adj);
    }
}


int isBridge(int V, vector<int> adj[], int c, int d)
{
    for (int i = 0; i < adj[c].size(); i++)
    {
        if (adj[c][i] == d)
        {
            adj[c].erase(adj[c].begin() + i);
            break;
        }
    }
    for (int i = 0; i < adj[d].size(); i++)
    {
        if (adj[d][i] == c)
        {
            adj[d].erase(adj[d].begin() + i);
            break;
        }
    }
    vector<int> vis(V, 0);

    dfs(c, vis, adj);

    if (!vis[d])
        return 1;

    return 0;
}

int main()
{
    int n,c,d;
    cin>>n>>c>>d;
    vector<int>adj[n];
    for(int i=0;i<n;i++)
    {
        int u , v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    cout<<isBridge(n,adj,c,d)<<endl;
    return 0;
}