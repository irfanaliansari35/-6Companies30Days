#include <bits/stdc++.h>
using namespace std;

int buyAnyNoOfTimes(int N, int A[])
{
    int profit = 0;
    for (int i = 1; i < N; i++)
    {
        if (A[i] > A[i - 1])
        {
            profit += (A[i] - A[i - 1]);
        }
    }

    return profit;
}
int maxProfit(int K, int N, int A[])
{
    // code here
    if (K == 0 || N == 1)
        return 0;
    if (2 * K >= N)
        return buyAnyNoOfTimes(N, A);

    vector<int> sell(K + 1, 0);
    vector<int> buy(K + 1, INT_MAX);

    for (int i = 0; i < N; i++)
    {
        int price = A[i];
        for (int j = 1; j <= K; j++)
        {
            buy[j] = min(buy[j], price - sell[j - 1]);
            sell[j] = max(sell[j], price - buy[j]);
        }
    }

    return sell[K];
}

int main()
{
    int n,k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout<<maxProfit(k,n,arr);
    return 0;
}