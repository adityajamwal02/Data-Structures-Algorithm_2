/*
Subset Sum Queries
Given an array and N number of queries, where in each query you have to check whether a subset whose sum is equal to given number exists in the array or not.
Input Format
In the function two vectors num and query are passed
Output Format
Return a bool vector of size N representing each query.

Sample Input
num[]   = {1, 2, 3}
query[] = {5, 3, 8}

Sample Output
{Yes, Yes, No}

Explanation
There is a subset with sum 5, subset is {2, 3}
There is a subset with sum 3, subset is {1, 2}
There is no subset with sum 8.
*/

/*
bitset::set() is a built-in STL in C++ which sets the bit to a given value at a particular index.
If no parameter is passed, it sets all bits to 1. If only a single parameter is passed, it sets the bit at that particular index to 1.
Syntax:
set(int index, bool val)

*/

/// Expected Time complexity O(1) for each query

#include<bits/stdc++.h>
using namespace std;

vector<bool> subsetSum(vector<int> num, vector<int> query)
{
    int N = query.size();
    vector<bool> result(N);
    bitset<10000> bit;
    bit.reset();
    bit[0]=1;
    for(int i=0;i<num.size();i++){
        bit=bit|(bit<<num[i]);
    }
    for(int i=0;i<N;i++){
        int x=query[i];
        bit[x]? result[i]=true : result[i]=false;
    }
    return result;
}
