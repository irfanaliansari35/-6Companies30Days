#include <bits/stdc++.h>
using namespace std;

int minDifference(int arr[], int n)
{
    // Your code goes here
    int range = 0;
    for (int i = 0; i < n; i++)
        range += arr[i];

    int dp[n + 1][range + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < range + 1; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < range + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    vector<int> v;
    for (int i = 0; i <= range / 2; i++)
    {
        if (dp[n][i])
            v.push_back(i);
    }

    int ans = INT_MAX;
    for (int i = 0; i < v.size(); i++)
    {
        ans = min(ans, range - 2 * v[i]);
    }

    return ans;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<minDifference(arr,n)<<endl;
    return 0;
}