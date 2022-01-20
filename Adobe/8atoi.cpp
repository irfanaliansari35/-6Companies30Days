#include <bits/stdc++.h>
using namespace std;

int atoi(string str)
{

    int n = str.length(), i = 0, f = 1;
    if (str[0] == '-')
    {
        f = -1;
        i++;
    }
    int ans = 0;
    for (i; i < n; i++)
    {
        if (!isdigit(str[i]))
            return -1;
        ans = ans * 10 + (str[i] - '0');
    }
    return f * ans;
}
int main()
{
    string s;
    cin >> s;
    cout << atoi(s) << endl;
    return 0;
}