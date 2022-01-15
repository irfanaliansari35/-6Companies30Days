#include <bits/stdc++.h>
using namespace std;

vector<int> calculateSpan(int price[], int n)
{

    if (n == 1)
        return {1};
    stack<int> st;
    vector<int> ngl;

    for (int i = 0; i < n; i++)
    {

        while (!st.empty() and price[st.top()] <= price[i])
            st.pop();
        if (st.empty())
            ngl.push_back(-1);
        else
            ngl.push_back(st.top());

        st.push(i);
    }

    for (int i = 0; i < n; i++)
        ngl[i] = i - ngl[i];

    return ngl;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<int>res = calculateSpan(arr,n);
    for(int x : res) cout<<x<<" ";
    cout<<endl;
    return 0;
}