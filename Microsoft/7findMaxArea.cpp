#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &grid, int i, int j, int n, int m, int &count)
{
    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0)
        return;

    grid[i][j] = 0;
    count++;
    dfs(grid, i - 1, j - 1, n, m, count);
    dfs(grid, i - 1, j, n, m, count);
    dfs(grid, i, j - 1, n, m, count);
    dfs(grid, i - 1, j + 1, n, m, count);
    dfs(grid, i + 1, j - 1, n, m, count);
    dfs(grid, i + 1, j, n, m, count);
    dfs(grid, i, j + 1, n, m, count);
    dfs(grid, i + 1, j + 1, n, m, count);
}

int findMaxArea(vector<vector<int>> &grid)
{
    
    int r = grid.size();
    int c = grid[0].size();
    int ans = INT_MIN;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == 1)
            {
                int count = 0;
                dfs(grid, i, j, r, c, count);
                ans = max(ans, count);
            }
        }

    return ans;
}

int main()
{
    int r,c;
    cin>>r>>c;
    vector<vector<int>>grid(r,vector<int>(c));
    for(int i=0;i<r;i++)
    for(int j=0;j<c;j++)
    {
        cin>>grid[i][j];
    }

    cout<<findMaxArea(grid)<<endl;
    return 0;
}