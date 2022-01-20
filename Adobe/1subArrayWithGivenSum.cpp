#include <bits/stdc++.h>
using namespace std;

vector<int> subarraySum(int arr[], int n, int s)
{
    int sum = 0;
    int i = 0, j = 0;
    while (j < n)
    {
        sum += arr[j];
        j++;
        while (sum > s and i < j)
        {
            sum -= arr[i];
            i++;
        }
        if (sum == s)
            return {i + 1, j};
    }
    return {-1};
}

int main()
{
    int n , s;
    cin>>n>>s;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int>res=subarraySum(arr,n,s);
    for(int x : res) cout<<x<<" ";
    cout<<endl;
    return 0;
}