#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestAP(int A[], int n)
{
    
    if (n == 1 || n == 2)
        return n;
    vector<vector<int>> dp(n, vector<int>(10001));
    int ans = 2;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int diff = A[i] - A[j];
            dp[i][diff] = max(dp[j][diff] + 1, 2);
            ans = max(ans, dp[i][diff]);
        }
    }

    return ans;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<lengthOfLongestAP(arr,n)<<endl;
    return 0;
}