#include <bits/stdc++.h>
using namespace std;

int minInsAndDel(int A[], int B[], int N, int M)
{

    vector<int> lis;
    unordered_set<int> st;
    for (int i = 0; i < M; i++)
    {
        st.insert(B[i]);
    }

    for (int i = 0; i < N; i++)
    {
        if (st.count(A[i]))
        {
            auto it = lower_bound(lis.begin(), lis.end(), A[i]);
            if (it == lis.end())
                lis.push_back(A[i]);
            else
                *it = A[i];
        }
    }

    return N + M - 2 * lis.size();
}

int main()
{
    int n , m;
    cin>>n>>m;
    int a[n], b[m];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    cout<<minInsAndDel(a,b,n,m)<<endl;
    return 0;
}