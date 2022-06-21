#include<bits/stdc++.h>
using namespace std;

int find_min(int x, int y, int z)
{
    return min(min(x, y), z);
}

void stringedit(string s1, string s2, int m, int n)
{
    //m-->s1
    //n-->s2
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0)
                dp[i][j]=j;
            else if(j==0)
                dp[i][j]=i;
            else if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=1+find_min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);
        }
    }
    for(int j=1;j<=n;j++)
    { for(int i=1;i<=m;i++)
        {
            cout<<dp[i][j];
        }
        cout<<endl;
    }

    cout<<endl;
    cout<<dp[m][n];
}
int main()
{
    string s1="spake";
    string s2="park";
    int m=s1.length();
    int n=s2.length();
    stringedit(s1,s2,m,n);
    return 0;
}
