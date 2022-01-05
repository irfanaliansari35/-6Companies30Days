//Q5 Print nth Ugly Number
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ull getNthUglyNo(int n)
{

    /*<<-----------------Approach 1--------------->>
    set<long long int>s;
    s.insert(1);
    n--;

    while(n--)
    {
        auto it = s.begin();
        long long int x = *it;
        s.erase(it);
        s.insert(x*2);
        s.insert(x*3);
        s.insert(x*5);
    }

    return *s.begin();*/

    //<<-----------------Approach 2--------------->>
    ull dp[n + 1];
    dp[0] = 1;

    int c2(0), c3(0), c5(0);
    for (int i = 1; i <= n; i++)
    {
        dp[i] = min({2 * dp[c2], 3 * dp[c3], 5 * dp[c5]});
        if (dp[i] == 2 * dp[c2])
            c2++;
        if (dp[i] == 3 * dp[c3])
            c3++;
        if (dp[i] == 5 * dp[c5])
            c5++;
    }

    return dp[n - 1];
}

int main()
{
    int n;
    cin >> n;
    auto ans = getNthUglyNo(n);
    cout << ans << endl;
    return 0;
}