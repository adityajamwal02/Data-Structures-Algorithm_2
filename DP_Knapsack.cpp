#include<bits/stdc++.h>
using namespace std;

int knapsack(int W, int N, int v[], int w[])
{
    int dp[N+1][W+1];
    for(int i=0;i<N+1;i++)
        dp[i][0]=0;
    for(int j=0;j<W+1;j++)
        dp[0][j]=0;
    for(int i=1;i<N+1;i++)
    {
        for(int j=1;j<W+1;j++)
        {
            if(w[i-1]<=j)
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i-1]]+v[i-1]);
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[N][W];
}
int main()
{
    int profits[]={1,2,3,4,5,6};
    int weights[]={2,3,4,5,6,7};
    cout<<knapsack(20,6,profits,weights);
    return 0;
}
