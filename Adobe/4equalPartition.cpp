#include <bits/stdc++.h>
using namespace std;

int equalPartition(int N, int arr[])
{
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += arr[i];
    if ((sum % 2) != 0)
        return 0;
    else
    {
        sum = sum / 2;
        bool t[N + 1][sum + 1];
        for (int i = 0; i < N + 1; i++)
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0)
                    t[i][j] = false;
                if (j == 0)
                    t[i][j] = true;
            }
        for (int i = 1; i < N + 1; i++)
            for (int j = 1; j < sum + 1; j++)
            {
                if (arr[i - 1] <= j)
                    t[i][j] = t[i - 1][j] || t[i - 1][j - arr[i - 1]];
                else
                    t[i][j] = t[i - 1][j];
            }
        if (t[N][sum] == true)
            return 1;
        else
            return 0;
    }
}

int main()
{
    
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<equalPartition(n,arr)<<endl;
    return 0;
}