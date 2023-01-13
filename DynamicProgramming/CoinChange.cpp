/*
Given a value N and an integer vector COINS representing coins of different denominations. Considering you have infinite supply of each coin, your task is to find total number of combinations of these coins that make a sum of N. If that amount of money cannot be made up by any combination of the coins, return 0.
Input Format
In the function an integer N is given, and a vector COINS consisting of coins.
Output Format
Return an integer representing total number of combinations.

Constraint
Total number of ways <= 10^12.
Sample Input
4 1 2 3

Sample Output
4

Explanation
{1, 1, 1, 1}, {1, 1, 2}, {1, 3}, {2, 2} are different combinations having a sum of 4.
*/


#include<bits/stdc++.h>
using namespace std;

long long coinChange(int i, int n, vector<int> coins, long long dp[500][100]){
    if(n<0 or i<0) return 0;
    if(i==0) return 1;
    if(dp[i][n]!=0){
        return dp[i][n];
    }
    long long op1=coinChange(i,n-1,coins,dp);
    long long op2=coinChange(i-coins[n],n,coins,dp);

    return dp[i][n]=op1+op2;
}

long long findCombinations(int n, vector<int> coins){
    long long dp[500][100]={0};
    return coinChange(n, coins.size()-1, coins, dp);
}

