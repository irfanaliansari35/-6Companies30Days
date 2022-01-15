#include <bits/stdc++.h>
using namespace std;

int minSteps(int D)
{
    

    int sum = 0, steps = 0;

    while (sum < D)
    {
        sum += (++steps);
    }

    while ((sum - D) % 2)
    {
        sum += (++steps);
    }

    return steps;
}

int main()
{
    int d;
    cin>>d;
    cout<<minSteps(d)<<endl;
    return 0;
}