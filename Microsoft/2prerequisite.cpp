#include<bits/stdc++.h>
using namespace std;

bool dfs(int node,vector<bool>&vis,vector<bool>&dfsVis,vector<int>adj[])
    {
        vis[node]=dfsVis[node]=true;
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,vis,dfsVis,adj)) return true;
            }
            else if(dfsVis[it]) return true;
        }
        dfsVis[node]=false;
        
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    
	    vector<int>adj[N];
	    vector<bool>vis(N);
	    vector<bool>dfsVis(N);
	    for(auto x : prerequisites)
	    {
	        int u = x.first;
	        int v = x.second;
	        adj[u].push_back(v);
	    }
	    
	    for(int i=0;i<N;i++)
	    {
	        if(!vis[i])
	        {
	            if(dfs(i,vis,dfsVis,adj)) return false;
	        }
	    }
	    
	    return true;
	    
	    
	}

int main()
{
    int n;
    cin>>n;
    vector<pair<int, int> > prerequisites(n);
    for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        prerequisites[i]={u,v};
    }

    cout<<isPossible(n,prerequisites)<<endl;
    return 0;
}