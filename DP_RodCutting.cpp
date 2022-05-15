//Bottom Up manner:

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int rodcut(int price[], int n)
{
    int dp[n+1];
    dp[0]=0;
    int i,j;

    for(i=1;i<=n;i++)
    {
        int max_value=INT_MIN;
        for(j=0;j<i;j++)
            max_value=max(max_value, price[j]+dp[i-j-1]);
        dp[i]=max_value;
    }
    return dp[n];
}
int main()
{
    int arr[]={1, 5, 8, 9, 10, 17, 17};
    int n=sizeof(arr)/sizeof(int);
    cout<<" Max Value: "<<rodcut(arr,n);
    return 0;
}
