#include <bits/stdc++.h>
using namespace std;

string amendSentence(string s)
{
    string res = "", token;
    token.push_back(tolower(s[0]));
    for (int i = 1; i < s.size(); i++)
    {
        char ch = s[i];
        if (isupper(ch))
        {
            res += token;
            res += " ";
            token = "";
            token.push_back(tolower(ch));
        }
        else
            token.push_back(tolower(ch));
    }

    res += token;
    return res;
}

int main()
{
    string s;
    cin>>s;
    cout<<amendSentence(s)<<endl;
    return 0;
}