/*
Given n friends, each one can remain single or can be paired up with some other friend.
Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.

Input Format
In the function an integer N is passed as parameter.

Output Format
Return an integer representing the total no. of ways

Sample Input
3

Sample Output
4

Explanation
{1}, {2}, {3} : all single
{1}, {2,3} : 2 and 3 paired but 1 is single.
{1,2}, {3} : 1 and 2 are paired but 3 is single.
{1,3}, {2} : 1 and 3 are paired but 2 is single.
Note that {1,2} and {2,1} are considered same.
*/

#include <bits/stdc++.h>
using namespace std;

int friendsPairing(int n)
{
    if(n==1)
        return 1;

    if(n==2)
        return 2;

    return (friendsPairing(n-1) + (n-1)*friendsPairing(n-2));
}
int main()
{
    int n;
    cin>>n;

    cout<<friendsPairing(n);

    return 0;
}
