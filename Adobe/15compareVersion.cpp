#include <bits/stdc++.h>
using namespace std;

void compareVersion(string version1, string version2)
{

    int d1 = count(version1.begin(), version1.end(), '.');
    int d2 = count(version2.begin(), version2.end(), '.');

    int diff = abs(d1 - d2);

    if (d1 > d2)
    {
        while (diff--)
        {
            version2 += ".0";
        }
    }
    else if (d2 > d1)
    {
        while (diff--)
        {
            version1 += ".0";
        }
    }

    replace(version1.begin(), version1.end(), '.', ' ');
    replace(version2.begin(), version2.end(), '.', ' ');

    stringstream ss1(version1);
    stringstream ss2(version2);

    int n1, n2;
    while (ss1 >> n1)
    {
        ss2 >> n2;
        if (n1 > n2)
            cout<<version1<<endl;
        else if (n2 > n1)
            cout<<version2<<endl;
    }

    cout<<"Both are equal"<<endl;
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    compareVersion(s1,s2);
    return 0;
}