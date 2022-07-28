#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// O(N) time and space

int power(int a, int n)
{
    if(n==0)
        return 1;

    return a*power(a,n-1);
}

// O(logN) time and space

int fastpower(int a, int n)
{
    if(n==0)
        return 1;
    if(n%2==0)
        return (fastpower(a,n/2)*fastpower(a,n/2));

    return (a*fastpower(a,n/2)*fastpower(a,n/2));
}

int main()
{
    int a=2;
    int n=10;

    cout<<power(a,n)<<endl;
    cout<<fastpower(a,n)<<endl;

    return 0;
}

