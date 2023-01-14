/*
Taro's summer vacation starts tomorrow, and he has decided to make plans for it now.
The vacation consists of N days. For each i (1≤i≤N), Taro will choose one of the following activities and do it on the i-th day:
A: Swim in the sea. Gain ai points of happiness.
B: Catch bugs in the mountains. Gain bi points of happiness.
C: Do homework at home. Gain ci points of happiness.
As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.
Find the maximum possible total points of happiness that Taro gains.
Input Format
In the function 3 vectors are passed.
Output Format
Print the maximum possible total points of happiness that Taro gains.

Sample Input
{10, 20, 30}
{40, 50, 60}
{70, 80, 90}

Sample Output
210

Explanation
If Taro does activities in the order C, B, C, he will gain 70+50+90=210 points of happiness.
*/

#include<bits/stdc++.h>
using namespace std;

int helper(vector<tuple<int,int,int>> &v, int n, int i, int dp[][4], int prev){
    if(i==n) return 0;
    if(dp[i][prev]!=-1){
        return dp[i][prev];
    }
    int op1=INT_MIN, op2=INT_MIN, op3=INT_MIN;
    if(prev!=1) op1=get<0>(v[i])+helper(v,n,i+1,dp,1);
    if(prev!=2) op1=get<1>(v[i])+helper(v,n,i+1,dp,2);
    if(prev!=3) op1=get<2>(v[i])+helper(v,n,i+1,dp,3);
return dp[i][prev]=max(op1, max(op2,op3));
}

int vacation(vector<int> a, vector<int> b, vector<int> c){
    vector<tuple<int, int, int>> v;
    int n=a.size();
    for(int i=0;i<n;i++){
        v.push_back(make_tuple(a[i], b[i], c[i]));
    }
    int dp[n][4];
    memset(dp,-1,sizeof(dp));
    return helper(v,n,0,dp,0);

}
