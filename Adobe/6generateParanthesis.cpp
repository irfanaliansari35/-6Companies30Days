#include <bits/stdc++.h>
using namespace std;

void generate(int open, int close, string op, vector<string> &res)
{
    if (open == 0 and close == 0)
    {
        res.push_back(op);
        return;
    }
    if (close < 0 or open < 0)
        return;

    string op1 = op;
    op1.push_back('(');
    generate(open - 1, close, op1, res);
    if (close > open)
    {
        string op2 = op;
        op2.push_back(')');
        generate(open, close - 1, op2, res);
    }
}
vector<string> AllParenthesis(int n)
{
    // Your code goes here
    vector<string> res;
    string op = "(";
    generate(n - 1, n, op, res);

    return res;
}

int main()
{
    int n;
    cin>>n;
    vector<string>res = AllParenthesis(n);
    for(string &s : res) cout<<s<<" ";
    cout<<endl;
    return 0;
}