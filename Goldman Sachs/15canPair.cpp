//Q15 Array Pair Sum Divisibility Problem 
#include<bits/stdc++.h>
using namespace std;

bool canPair(vector<int> nums, int k) {
        // Code here.
        int n = nums.size();
        if(n&1) return false;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]%k]++;
        }
        
        for(int i=0;i<n;i++)
        {
            int rem =nums[i]%k;
            if(rem==0)
            {
                if(mp[rem]&1) return false;
            }
            else if(mp[rem]!=mp[k-rem]) return false;
            
        }    
        
        return true;
    }

int main()
{
     int n, k;
    cin>>n>>k;
    vector<int>v(n);
    for(int &x : v) cin>>x;
    cout<<canPair(v,k)<<endl;
    return 0;
}