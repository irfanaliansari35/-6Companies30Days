//Q14 Minimum Size Subarray Sum Len
#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{

    int n = nums.size();
    if (n == 1)
        return nums[0] >= target;
    int i = 0, j = 0;
    int preSum = 0;
    int ans = INT_MAX;
    while (j < n)
    {
        preSum += nums[j];

        while (preSum >= target and i <= j)
        {
            ans = min(ans, j - i + 1);
            preSum -= nums[i];
            i++;
        }

        j++;
    }

    return ans == INT_MAX ? 0 : ans;
}

int main()
{
    int n, target;
    cin>>n>>target;
    vector<int>v(n);
    for(int &x : v) cin>>x;
    cout<<minSubArrayLen(target,v)<<endl;
    return 0;
}