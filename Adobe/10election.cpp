#include <bits/stdc++.h>
using namespace std;

vector<string> winner(string arr[], int n)
{
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    string name = "", vote = "0";
    for (auto x : mp)
    {
        if (x.second > stoi(vote) || (x.second == stoi(vote) && x.first < name))
        {
            name = x.first;
            vote = to_string(x.second);
        }
    }
    return {name, vote};
}

int main()
{
    int n;
    cin>>n;
    string arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<string>res = winner(arr,n);
    for(string &s : res) cout<<s<<" ";
    cout<<endl;
    return 0;
}