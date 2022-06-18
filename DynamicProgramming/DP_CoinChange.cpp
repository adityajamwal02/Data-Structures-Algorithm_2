#include<bits/stdc++.h>
#include<vector>
using namespace std;

int coinchange(int target, vector<int> denoms)
{
    vector<int> dp(target+1,0);
    dp[0]=0;
    for(int i=1;i<=target;i++)
    {
        dp[i]=INT_MAX;

        for(int c: denoms)
        {
            if(i-c>=0 and dp[i-c]!=INT_MAX)
                dp[i]=min(dp[i],dp[i-c]+1);
        }
    }
    return  dp[target]==INT_MAX? -1:dp[target];
}
int main()
{
    vector<int> denoms={1,2,5,10,20};
    int target=29;
    cout<<coinchange(target,denoms);
    return 0;
}
