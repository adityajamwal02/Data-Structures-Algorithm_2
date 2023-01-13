/*
Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.
If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.
Input Format
In the function an integer vector is passed.
Output Format
Return an integer representing minimum difference.
Sample Input
{1, 6, 11, 5}
Sample Output
1
Explanation
Subset1 = {1, 5, 6}, sum of Subset1 = 12
Subset2 = {11}, sum of Subset2 = 11
*/



#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> arr)
{
    int n=arr.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }
    for(int i=1;i<=sum;i++){
        dp[0][i]=false;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            dp[i][j]=dp[i-1][j];
            if(arr[i-1]<=j){
                dp[i][j] |= dp[i-1][j-arr[i-1]];
            }
        }
    }
    int diff=INT_MAX;
    for (int j = sum / 2; j >= 0; j--) {
        if (dp[n][j] == true) {
            diff = sum-2*j;
            break;
        }
    }
    return diff;
}
