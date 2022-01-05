//Q3 Count the subarrays having product less than k
#include <bits/stdc++.h>
using namespace std;

int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k)
{

    if (n == 1)
    {
        if (a[0] < k)
            return 1;
        else
            return 0;
    }

    long long prePro = 1;
    int i = 0, j = 0;
    long count = 0;
    while (j < n)
    {
        prePro *= a[j];

        while (prePro >= k and i <= j)
        {
            prePro /= a[i];
            i++;
        }

        count += (j - i + 1);

        j++;
    }

    return (int)count;
}

int main()
{
    int n;
    long long k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    cout << countSubArrayProductLessThanK(v, n, k) << endl;
    return 0;
}