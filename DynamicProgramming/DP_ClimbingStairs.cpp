/*
Frog Jump, Climbing Stairs Problem--> Can move 1 or 2 steps and there is cost
for each move, find the minimum cost/energy required to cover the N stairs.
*/


#include<vector>
#include<iostream>
using namespace std;

int frogjump(int n, vector<int> &jumps, vector<int> &dp)
{
    if(n==0)
        return 0;
    if(dp[n]!=-1)
        return dp[n];

    int right=INT_MAX;
    int left=frogjump(n-1, jumps, dp) + abs(jumps[n]-jumps[n-1]);
    if(n>1)
        right=frogjump(n-2, jumps, dp) + abs(jumps[n]-jumps[n-2]);

    return dp[n]=min(left, right);
}

int main()
{
    int n;
    cin>>n;

    vector<int> jumps={30, 10, 60, 10, 60, 50};
    vector<int> dp(n+1,-1);
    cout<<frogjump(n-1, jumps, dp);

    return 0;
}
