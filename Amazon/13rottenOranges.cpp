#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    queue<pair<int, int>> q;
    int t = -1;
    vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                grid[i][j] = 3;
                q.push({i, j});
            }
        }
    }

    while (!q.empty())
    {
        int k = q.size();
        while (k--)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (auto dir : directions)
            {
                int nextX = x + dir.first;
                int nextY = y + dir.second;

                if (nextX >= 0 and nextX < n and nextY >= 0 and nextY < m and grid[nextX][nextY] == 1)
                {
                    q.push({nextX, nextY});
                    grid[nextX][nextY] = 3;
                }
            }
        }
        t++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                return -1;
            }
        }
    }

    return t == -1 ? 0 : t;
}

int main()
{
    int n , m;
    cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(m));
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
        cin>>grid[i][j];
    }

    cout<<orangesRotting(grid)<<endl;
    return 0;
}