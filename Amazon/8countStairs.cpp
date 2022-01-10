#include <bits/stdc++.h>
using namespace std;

long long countWays(int m)
{
    // your code here
    long long dp[m + 1] = {0};
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= m; i++)
    {
        dp[i] = dp[i - 2] + 1;
    }
    return dp[m];
}

int main()
{
    int n ;
    cin>>n;
    cout<<countWays(n)<<endl;
    return 0;
}