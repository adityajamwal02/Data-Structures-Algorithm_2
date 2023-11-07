/// Flyod Warshall

#include<bits/stdc++.h>
using namespace std;

int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges){
    vector<vector<int>> dp(n+1,vector<int>(n+1,1e9));
    for(int i=1;i<=n;i++){
        dp[i][i]=0;
    }
    for(auto edge : edges){
        int u=edge[0], v=edge[1], w=edge[2];
        dp[u][v]=w;
    }
    for(int via=1;via<=n;via++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dp[i][via]!=1e9 and dp[via][j]!=1e9){
                    dp[i][j]=min(dp[i][j],dp[i][via]+dp[via][j]);
                }
            }
        }
    }
    return dp[src][dest];
}
