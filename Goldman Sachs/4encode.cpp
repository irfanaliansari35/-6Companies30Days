//Q4 Given a string, Your task is to  complete the function encode that returns the run length encoded string for the given string.
#include <bits/stdc++.h>
using namespace std;

string encode(string src)
{

    if (src.size() == 1)
    {
        return src + "1";
    }
    src.push_back('$');
    string res = "";
    int cnt = 1, n = src.size();
    for (int i = 1; i < n; i++)
    {
        if (src[i] == src[i - 1])
            cnt++;
        else
        {
            res.push_back(src[i - 1]);
            res += to_string(cnt);
            cnt = 1;
        }
    }

    return res;
}

int main()
{
    string s;
    cin >> s;
    cout << encode(s) << endl;
    return 0;
}