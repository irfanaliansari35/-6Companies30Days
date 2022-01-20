#include <bits/stdc++.h>
using namespace std;

string next(string s)
{
    bool val = next_permutation(s.begin(), s.end());
    if (val == false)
        return "";
    return s;
}
string nextPalin(string N)
{
    
    int n = N.size();
    int mid = n / 2;
    string str = N.substr(0, mid);
    string nextGreater = next(str);
    if (nextGreater == "")
        return "-1";

    // cout<<nextGreater<<endl;

    if (n % 2 == 1)
    {
        string rev = nextGreater;
        reverse(rev.begin(), rev.end());
        string palindrome = nextGreater + N[mid] + rev;

        return palindrome;
    }

    string rev = nextGreater;
    reverse(rev.begin(), rev.end());

    return nextGreater + rev;
}

int main()
{
    string n;
    cin>>n;
    cout<<nextPalin(n)<<endl;
    return 0;
}