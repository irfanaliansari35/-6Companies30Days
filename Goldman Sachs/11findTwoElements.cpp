#include <bits/stdc++.h>
using namespace std;

void findTwoElement(int *arr, int n)
{
    //<<-------------Approach 1----------->>
    // int a;
    // int b;
    // for(int i=0;i<n;i++)
    // {
    //     if(arr[abs(arr[i])-1]<0)
    //     {
    //          a=abs(arr[i]);
    //     }
    //     else
    //         arr[abs(arr[i])-1] = - arr[abs(arr[i])-1];
    // }
    // for(int i=0;i<n;i++)
    //     {
    //         if(arr[i]>0)
    //       {
    //             b=i+1;
    //             break;
    //       }
    //     }
    
    //cout<<a<<" "<<b<<endl;

    //<<-------------Approach 2----------->>

    int i = 0;
    while (i < n)
    {
        if (arr[i] != arr[arr[i] - 1])
            swap(arr[i], arr[arr[i] - 1]);
        else
            i++;
    }

    int a, b;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
        {
            a = arr[i];
            b = i + 1;
            break;
        }
    }

    cout<<a<<" "<<b<<endl;

    return;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    findTwoElement(arr,n);
    return 0;
}