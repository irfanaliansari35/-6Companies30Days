#include <bits/stdc++.h>
using namespace std;

string colName(long long int n)
{
    // your code here
    string res;
    while (n)
    {
        n--;
        char temp = 'A' + (n % 26);
        res.push_back(temp);
        n = n / 26;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    long long int n;
    cin>>n;
    cout<<colName(n)<<endl;
    return 0;
}