#include <bits/stdc++.h>
using namespace std;

int numOfWays(int n, int x)
{
    int mod = 1e9 + 7;
    long long dp[n + 1];
    memset(dp, 0, sizeof dp);

    dp[0] = dp[1] = 1;
    int maxLimit = pow(n, 1.0 / x);

    for (int i = 2; i <= maxLimit; i++)
    {
        int currPow = pow(i, x);
        for (int j = n; j >= currPow; j--)
        {
            dp[j] = (dp[j] % mod + dp[j - currPow] % mod) % mod;
        }
    }

    return (int)dp[n];
}

int main()
{
    int n,x;
    cin>>n>>x;
    cout<<numOfWays(n,x)<<endl;
    return 0;
}