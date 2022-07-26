#include<iostream>
using namespace std;

int ClearLastIBits(int n, int i)
{
    int mask=(~0<<i);
    return n&mask;

}

int main()
{
    int n=15;
    int i=2;
    cout<<ClearLastIBits(n,i);

    return 0;

}
