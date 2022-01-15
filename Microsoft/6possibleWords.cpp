#include <bits/stdc++.h>
using namespace std;

void findComb(vector<string> &res, string path, int idx, int a[], int n, vector<string> &keypad)
{
    if (idx == n)
    {
        res.push_back(path);
        return;
    }

    int num = a[idx];
    if (num == 0 or num == 1)
        findComb(res, path, idx + 1, a, n, keypad);
    string word = keypad[num];
    for (int i = 0; i < word.size(); i++)
    {
        findComb(res, path + word[i], idx + 1, a, n, keypad);
    }
}
vector<string> possibleWords(int a[], int N)
{
    //Your code here
    vector<string> res;
    vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string path = "";
    findComb(res, path, 0, a, N, keypad);

    return res;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<string>res = possibleWords(arr,n);
    for(auto &s : res)
    {
        cout<<s<<" ";
    }
    return 0;
}