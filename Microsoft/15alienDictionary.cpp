#include <bits/stdc++.h>
using namespace std;

void topoSort(int node, vector<bool> &vis, vector<int> adj[], stack<int> &st)
{
    vis[node] = true;
    for (auto it : adj[node])
    {
        if (!vis[it])
            topoSort(it, vis, adj, st);
    }
    st.push(node);
}
string findOrder(string dict[], int N, int K)
{
    
    vector<int> adj[K];
    vector<bool> vis(N, false);
    for (int i = 0; i < N - 1; i++)
    {
        string str1 = dict[i];
        string str2 = dict[i + 1];
        int j = 0, k = 0;
        while (j < str1.size() and k < str2.size())
        {
            if (str1[j] != str2[k])
            {
                adj[str1[j] - 'a'].push_back(str2[k] - 'a');
                break;
            }
            j++;
            k++;
        }
    }
    stack<int> st;
    for (int i = 0; i < K; i++)
    {
        if (!vis[i])
            topoSort(i, vis, adj, st);
    }
    string res;
    while (!st.empty())
    {
        int ch = st.top();
        st.pop();
        res.push_back(ch + 'a');
    }
    return res;
}

int main()
{
    int n,k;
    cin>>n>>k;
    string arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<findOrder(arr,n,k)<<endl;
    return 0;
}