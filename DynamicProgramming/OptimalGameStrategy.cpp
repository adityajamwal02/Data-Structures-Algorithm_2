/*
Oswald and Henry are playing the game of coins. They have a row of 'n' coins [C1,C2,C3...Cn] with values [V1,V2,V3...Vn] where Ci coin has Vi value. They take turns alternatively. In one turn the player can pick either the first or the last coin of the row. Given both Oswald and Henry are very smart players, you need to find the maximum possible value Oswald can earn if he plays first.
Input Format:
In the function you are given an integer N i.e. the number of coins and a vector V which represents the values of each coin in the row respectively.
Output Format: Return a single integer which is the maximum possible value as asked in the question.
Constraints: 1<=N<=15 1<=V[i]<=1000
Sample Testcase:
Input: 4 1 2 3 4
Output: 6
Explanation: Oswald will pick up coin with value 4, Henry will pick coin with value 3, Oswald will pick 2 and Henry will pick 1. Hence 4+2=6.
*/

#include <bits/stdc++.h>
using namespace std;

int game(int n, vector<int> v, int start, int end){
    if(start==end or start==end-1){
        return max(v[start], v[end]);
    }
    int op1=v[start]+min(game(n,v,start+2,end), game(n,v,start+1,end-1));
    int op2=v[end]+min(game(n,v,start+1,end-1), game(n,v,start,end-2));
    return max(op1, op2);
}
int MaxValue(int n, vector<int> v){
    int res=game(n,v,0,n-1);
    return res;
}
