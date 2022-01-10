#include <bits/stdc++.h>
using namespace std;

int isValid(vector<vector<int>> mat)
{
    unordered_set<string> seen;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (mat[i][j] == 0)
                continue;
            string row = "row" + to_string(i) + to_string(mat[i][j]);
            string col = "col" + to_string(j) + to_string(mat[i][j]);
            string box = "box" + to_string((i / 3) * 3 + (j / 3)) + to_string(mat[i][j]);
            if (seen.count(row))
                return false;
            else
                seen.insert(row);
            if (seen.count(col))
                return false;
            else
                seen.insert(col);
            if (seen.count(box))
                return false;
            else
                seen.insert(box);
        }
    }

    return true;
}

int main()
{
    vector<vector<int>>mat(9,vector<int>(9,0));
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            cin>>mat[i][j];
        }
    cout<<isValid(mat)<<endl;;
    return 0;
}