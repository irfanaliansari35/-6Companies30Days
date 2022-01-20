#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(int a[], int n)
{
    stack<int> st;
    vector<int> res;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() and a[i] >= st.top())
            st.pop();
        if (st.empty())
        {
            st.push(a[i]);
            res.push_back(a[i]);
        }
    }

    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int>res = leaders(arr,n);
    for(int x : res) cout<<x<<" ";
    cout<<endl;
    return 0;
}