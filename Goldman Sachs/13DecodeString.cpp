//Q13 Decode String
#include <bits/stdc++.h>
using namespace std;

string decodedString(string s)
{
    // code here
    stack<string> chars;
    stack<int> nums;
    string res;
    int num = 0;
    for (char c : s)
    {
        if (isdigit(c))
        {
            num = num * 10 + (c - '0');
        }
        else if (isalpha(c))
        {
            res.push_back(c);
        }
        else if (c == '[')
        {
            chars.push(res);
            nums.push(num);
            res = "";
            num = 0;
        }
        else if (c == ']')
        {
            string tmp = res;
            for (int i = 0; i < nums.top() - 1; ++i)
            {
                res += tmp;
            }
            res = chars.top() + res;
            chars.pop();
            nums.pop();
        }
    }
    return res;
}

int main()
{
    string s;
    cin >> s;
    cout << decodedString(s) << endl;
    return 0;
}