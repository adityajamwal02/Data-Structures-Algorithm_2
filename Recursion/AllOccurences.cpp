/*
All Occurence!
You are given an integer array of size N. Your aim is to find all the occurrences (indices) of a given element.
Input format:
Vector V and integer k (to find) are passed as parameters.
Output parameter:
Return a vector of integers containing all the indices in sorted manner.
Sample Input:
3
1 2 5 3 1 2 3 8 6 3 6 7 9
Sample Output:
3 6 9
*/

#include <bits/stdc++.h>
using namespace std;

void helper(int i, vector<int> v, vector<int> &result, int k, int n){
    if(i==n){
        return;
    }
    if(v[i]==k){
        result.push_back(i);
    }
    helper(i+1,v,result,k,n);
return;
}
vector<int> findAllOccurences(int k, vector<int> v){
    int n=v.size();
    vector<int> result;
    helper(0,v,result,k,n);
return result;
}
