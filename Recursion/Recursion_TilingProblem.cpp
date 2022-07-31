/* You are given N tiles of size 1 x M, There is a floor of size N x M which you have to cover with tiles.
Find the number of ways the floor can be completely covered if you can place the tiles in both horizontal and vertical manner.

Input Format:
In the function, two integers N and M are passed.

Output Format:
Return a single integer denoting the number of ways.

Sample Input:
4 3

Sample Output:
3
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Tiles(int n,int m)
{
    //base case
    if(n<m)
        return 1;

    if(n==m)
        return 2;

    return Tiles(n-1,m) + Tiles(n-m,m);
}

int main()
{
    int n,m;
    cin>>n>>m;

    cout<<Tiles(n,m);

    return 0;
}
