#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> phoneDirectory(vector<string> &contacts, string searchWord)
{
    sort(contacts.begin(), contacts.end());
    vector<vector<string>> res;
    string curr = "";
    auto it = contacts.begin();
    for (auto ch : searchWord)
    {
        curr += ch;
        vector<string> suggested;
        it = lower_bound(it, contacts.end(), curr);
        for (int i = 0; i < 3 and it + i < contacts.end(); i++)
        {
            string &s = *(it + i);
            if (s.find(curr) == string::npos)
                break;
            suggested.push_back(s);
        }

        res.push_back(suggested);
    }

    return res;
}

int main()
{   
    int n;
    cin>>n;
    vector<string>contacts(n);
    string searchWord;
    for(auto &s : contacts) cin>>s;
    cin>>searchWord;
    vector<vector<string>> res = phoneDirectory(contacts,searchWord);
    return 0;
}