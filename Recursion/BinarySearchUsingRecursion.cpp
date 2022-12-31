/*

Binary Search using Recursion!
Given a sorted array, return the index of an element x in the array. Use binary search to find the element in the array !
Return -1 if the element is not present.
Input Format
In the function an integer vector  is passed.
Output Format
Return an integer denoting index of the element to be find.

Sample Input
{1, 3, 5, 7, 9}, x = 3
Sample Output
1
Explanation
3 is present at index 2.
*/

#include <bits/stdc++.h>
using namespace std;

int helper(int low, int high, vector<int> v, int x){
    int mid=low+(high-low)/2;
    if(v[mid]==x){
        return mid;
    }else if(v[mid]>x){
        return helper(low,mid-1,v,x);
    }else if(v[mid]<x){
        return helper(mid+1,high,v,x);
    }
    return -1;
}
int binarySearch(vector<int> v, int x)
{
    int n=v.size();
    return helper(0,n-1,v,x);
}
