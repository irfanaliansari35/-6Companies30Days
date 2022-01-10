#include <bits/stdc++.h>
using namespace std;

int getOrder(char ch)
{
    switch (ch)
    {
    case '!':
        return 9;
    case '#':
        return 8;
    case '$':
        return 7;
    case '%':
        return 6;
    case '&':
        return 5;
    case '*':
        return 4;
    case '@':
        return 3;
    case '^':
        return 2;
    case '~':
        return 1;
    }

    return -1;
}

bool comp(char a, char b)
{
    return getOrder(a) > getOrder(b);
}
void matchPairs(char nuts[], char bolts[], int n)
{

    sort(nuts, nuts + n, comp);
    sort(bolts, bolts + n, comp);
}

int main()
{
    int n;
    cin >> n;
    char nuts[n], bolts[n];
    for (int i = 0; i < n; i++)
        cin >> nuts[i];
    for (int i = 0; i < n; i++)
        cin >> bolts[i];

    matchPairs(nuts, bolts, n);

    for (int i = 0; i < n; i++)
        cout << nuts[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << bolts[i] << " ";

    return 0;
}