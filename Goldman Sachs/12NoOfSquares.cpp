//Q12 Find total number of Squares in a N*N chessboard
#include <bits/stdc++.h>
using namespace std;

long long squaresInChessBoard(long long N)
{

    long long ans = (N * (N + 1) * (2 * N + 1)) / 6;

    return ans;
}

int main()
{
    long long n;
    cin >> n;
    cout << squaresInChessBoard(n) << endl;
    return 0;
}