//Q1 Given an array of strings, return all groups of strings that are anagrams.
#include<bits/stdc++.h>
using namespace std;

void anagrams(vector<string>& string_list) 
{
    
    vector<vector<string>>res;
    unordered_map<string,vector<string>>mp;
    
    for(int i=0;i<string_list.size();i++)
    {
        string s=string_list[i];
        sort(s.begin(),s.end());
        mp[s].push_back(string_list[i]);
    }
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        for(auto s : it->second)
        {
            cout<<s<<" ";
        }
        cout<<endl;
    }

    
}

int main()
{   
    int n;
    cin>>n;
    vector<string>string_list(n);
    for(string &s : string_list)
        cin>>s;
    anagrams(string_list);
    return 0;
}