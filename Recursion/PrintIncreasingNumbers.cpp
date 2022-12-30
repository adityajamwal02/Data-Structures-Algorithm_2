/*
Print Increasing Numbers
Given an integer N. Your task is to return an integer vector containing numbers from 1 to N in increasing order.
Sample Input
5
Sample Output
1 2 3 4 5
*/

/// Iterative

#include<bits/stdc++.h>
using namespace std;

vector<int> increasingNumbers(int N) {
    vector<int> result;
    for(int i=1;i<=N;i++){
        result.push_back(i);
    }
    return result;
}

/// Recursive

#include<bits/stdc++.h>
using namespace std;

void recursion(int i,vector<int> &result, int N){
    if(i>N){
        return;
    }
    result.push_back(i);
    return recursion(i+1, result, N);
}
vector<int> increasingNumbers(int N) {
    vector<int> result;
    recursion(1, result, N);
return result;
}
