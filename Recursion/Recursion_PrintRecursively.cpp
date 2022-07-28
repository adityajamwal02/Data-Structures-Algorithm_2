
// PRINT NUMBERS 1 TO N RECUSRIVELY IN DECREASING AND INCREASING ORDER

#include<iostream>
using namespace std;

void printRecursivelyDecrease(int n)
{
    if(n==0)
        return;

    cout<<n<<" ";
    printRecursivelyDecrease(n-1);
}

void printRecursivelyIncrease(int i,int n)
{
    if(i==n+1)
        return;

    cout<<i<<" ";
    printRecursivelyIncrease(i+1,n);
}

int main()
{
    int n;
    cin>>n;
    int i;

    printRecursivelyDecrease(n);
    cout<<endl;
    printRecursivelyIncrease(1,n);

    return 0;
}
