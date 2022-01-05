//Q6 Given two strings str1 and str2. We say that str2 divides str1 if it's possible
#include<bits/stdc++.h>
using namespace std;

string gcdOfStrings(string str1, string str2) {
        
        int n1 = str1.size();
        int n2 = str2.size();
        if(str1+str2==str2+str1)
        {
            return str1.substr(0,__gcd(n1,n2));
        }
        
        return "";
    }

int main()
{
    string s1, s2;
    cin>>s1 >> s2;
    cout<<gcdOfStrings(s1,s2);
    return 0;
}