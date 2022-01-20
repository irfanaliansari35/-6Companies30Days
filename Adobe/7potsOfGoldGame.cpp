#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
long long solve(int i, int n, vector<int> &v)
{
    if (i >= n)
        return 0;
    if (n <= 0)
        return 0;

    if (dp[i][n] != -1)
        return dp[i][n];
    int sum1 = v[i] + min(solve(i + 1, n - 1, v), solve(i + 2, n, v));
    int sum2 = v[n - 1] + min(solve(i + 1, n - 1, v), solve(i, n - 2, v));
    return dp[i][n] = max(sum1, sum2);
}
int maxCoins(vector<int> &A, int n)
{
    
    memset(dp, -1, sizeof dp);
    return solve(0, n, A);
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int &x : v) cin>>x;
    cout<<maxCoins(v,n)<<endl;
    return 0;
}