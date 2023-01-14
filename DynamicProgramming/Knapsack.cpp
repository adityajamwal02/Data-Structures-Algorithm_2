#include<iostream>
#include<vector>
using namespace std;

// Recursion
int knapsack(int wts[], int prices[], int n, int w){
    if(n==0 or w==0) return 0; //Base case

    //Recursive case
    int inc=0, exc=0;
    if(wts[n-1]<=w){
        inc=prices[n-1]+knapsack(wts,prices,n-1,w-wts[n-1]);
    }
    exc=knapsack(wts,prices,n-1,w);
    return max(inc,exc);
}

//Bottom-Up (Tabulation DP)
int knapsackDp(int wts[], int prices[], int n, int w){
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            int inc=0, exc=0;
            if(wts[i-1]<=w){
                inc=prices[i-1]+dp[i-1][w-wts[i-1]];
            }
            exc=dp[i-1][w];
            dp[i][j]=max(inc, exc);
        }
    }
    return dp[n][w];
}


int main(){

    int wts[]={2,7,3,4};
    int prices[]={5,20,20,10};
    int n=4;
    int w=11;

    cout<<knapsackDp(wts,prices,n,w)<<endl;

    return 0;
}
