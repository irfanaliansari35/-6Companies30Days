#include<bits/stdc++.h>
using namespace std;

vector<int> tenLargestNums(vector<int>&nums,long n)
{
    if(n<=10)
    {
        sort(begin(nums),end(nums));
        return nums;
    }
    priority_queue<int,vector<int>,greater<int>>pq;
    vector<int>res;
    for(int i : nums)
    {
        pq.push(i);
        if(pq.size()>10) pq.pop();
    }

    while(!pq.empty())
    {
        res.push_back(pq.top());
        pq.pop();
    }

    return res;
}

int main()
{
    long n;
        cin>>n; 
    vector<int>nums(n); 
    for(int &x : nums) 
        cin>>x;
    vector<int>ans = tenLargestNums(nums,n);
    for(int x : ans)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}