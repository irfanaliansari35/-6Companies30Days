#include <bits/stdc++.h>
using namespace std;

void spirallyTraverse(vector<vector<int>> matrix, int r, int c)
{
    // code here
    int minr = 0, minc = 0;
    int maxr = r - 1, maxc = c - 1;
    int total = r * c;
    int count = 0;
    vector<int> res;
    while (count < total)
    {
        //Top Wall
        for (int i = minr, j = minc; j <= maxc && count < total; j++)
        {
            cout << matrix[i][j];
            count++;
        }
        minr++;

        //Right Wall
        for (int i = minr, j = maxc; i <= maxr && count < total; i++)
        {
            cout << matrix[i][j];
            count++;
        }
        maxc--;

        //Bottom Wall
        for (int i = maxr, j = maxc; j >= minc && count < total; j--)
        {
            cout << matrix[i][j];
            count++;
        }
        maxr--;

        //Left Wall
        for (int i = maxr, j = minc; i >= minr && count < total; i--)
        {
            cout << matrix[i][j];
            count++;
        }
        minc++;
    }
}

int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> matrix(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> matrix[i][j];
        }
    }
    return 0;
}