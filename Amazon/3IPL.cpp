#include <bits/stdc++.h>
using namespace std;

vector<int> max_of_subarrays(vector<int> arr, int n, int k)
{
    // your code here
    list<int> ls;
    vector<int> res;
    int i = 0, j = 0;
    while (j < n)
    {
        while (ls.size() > 0 and arr[j] > ls.back())
            ls.pop_back();

        ls.push_back(arr[j]);

        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            res.push_back(ls.front());
            if (arr[i] == ls.front())
            {
                ls.pop_front();
            }
            i++;
            j++;
        }
    }

    return res;
}

int main()
{
    int n , k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int &x : arr) cin>>x;
    vector<int>res=max_of_subarrays(arr,n,k);
    for(int &x : res) cout<<x<<" ";
    cout<<endl;
    return 0;
}