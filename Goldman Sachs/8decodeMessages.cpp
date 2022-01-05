//Q8 Total Decoding Messages
#include <bits/stdc++.h>
using namespace std;

int solve(int idx, vector<int> &dp, string &s, int n)
{
    if (idx == n)
        return 1;
    if (s[idx] == '0')
        return 0;
    if (dp[idx] != -1)
        return dp[idx];

    int res = solve(idx + 1, dp, s, n);

    if (idx < n - 1 && (s[idx] == '1' or (s[idx] == '2' && s[idx + 1] < '7')))
        res += solve(idx + 2, dp, s, n);

    return dp[idx] = res;
}

int numDecodings(string s)
{
    int n = s.size();

    vector<int> dp(n + 1, -1);
    return solve(0, dp, s, n);
}

int main()
{
    string s;
    cin>>s;
    cout<<numDecodings(s)<<endl;
    return 0;
}