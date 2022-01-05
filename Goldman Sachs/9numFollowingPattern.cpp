//Q9 Given a pattern containing only I's and D's. I for increasing and D
#include <bits/stdc++.h>
using namespace std;

string printMinNumberForPattern(string S)
{

    string ans = "";
    stack<int> st;
    int num = 1;
    for (auto ch : S)
    {
        if (ch == 'D')
        {
            st.push(num++);
        }
        else
        {
            st.push(num++);
            while (!st.empty())
            {
                ans.push_back(st.top() + '0');
                st.pop();
            }
        }
    }
    st.push(num);
    while (!st.empty())
    {
        ans.push_back(st.top() + '0');
        st.pop();
    }

    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << printMinNumberForPattern(s) << endl;
    return 0;
}