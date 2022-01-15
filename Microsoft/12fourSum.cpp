#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &arr, int k)
{
    
    sort(arr.begin(), arr.end());
    vector<vector<int>> res;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int target2 = k - arr[i] - arr[j];
            int front = j + 1;
            int rear = n - 1;
            while (front < rear)
            {
                if (arr[front] + arr[rear] < target2)
                    front++;
                else if (arr[front] + arr[rear] > target2)
                    rear--;
                else
                {
                    vector<int> quad(4, 0);
                    quad[0] = arr[i];
                    quad[1] = arr[j];
                    quad[2] = arr[front];
                    quad[3] = arr[rear];
                    res.push_back(quad);
                    while (front < rear and quad[2] == arr[front])
                        front++;
                    while (front < rear and quad[3] == arr[rear])
                        rear--;
                }
            }

            while (j < n and arr[j] == arr[j + 1])
                j++;
        }
        while (i < n and arr[i] == arr[i + 1])
            i++;
    }
    return res;
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int &x : v) cin>>x;
    vector<vector<int>> res = fourSum(v,k);
    for(auto &v : res)
    {
        for(auto &u : v) cout<<u<<" ";

        cout<<endl;
    }
    return 0;
}