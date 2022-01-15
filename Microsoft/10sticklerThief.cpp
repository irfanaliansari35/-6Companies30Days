#include <bits/stdc++.h>
using namespace std;

int FindMaxSum(int arr[], int n)
{
    
    if (n == 1)
        return arr[0];
    int dp[n] = {0};
    dp[0] = arr[0];
    if (n > 1)
    {
        dp[1] = max(arr[0], arr[1]);
    }

    for (int i = 2; i < n; i++)
    {
        dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]);
    }

    return dp[n - 1];
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<FindMaxSum(arr,n)<<endl;
    return 0;
}