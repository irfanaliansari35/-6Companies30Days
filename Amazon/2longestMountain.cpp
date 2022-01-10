#include <bits/stdc++.h>
using namespace std;

int longestMountain(vector<int> &arr)
{
    int n = arr.size();
    int ans = 0;
    for (int i = 1; i < n - 1;)
    {
        if (arr[i] > arr[i - 1] and arr[i] > arr[i + 1])
        {
            int j = i;
            int cnt = 1;
            while (j > 0 and arr[j] > arr[j - 1])
            {
                j--;
                cnt++;
            }

            while (i < n - 1 and arr[i] > arr[i + 1])
            {
                cnt++;
                i++;
            }

            ans = max(ans, cnt);
        }
        else
            i++;
    }

    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int &x : arr) cin>>x;
    cout<<longestMountain(arr);
    return 0;
}