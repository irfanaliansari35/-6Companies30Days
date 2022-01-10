#include <bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string A)
{
    // Code here
    int mp[256] = {0};
    queue<char> q;
    string res;
    for (auto ch : A)
    {
        mp[ch]++;
        q.push(ch);
        while (q.size() > 0 and mp[q.front()] > 1)
            q.pop();

        if (q.size() == 0)
            res.push_back('#');
        else
            res.push_back(q.front());
    }

    return res;
}

int main()
{
    string s;
    cin>>s;
    cout<<FirstNonRepeating(s)<<endl;
    return 0;
}