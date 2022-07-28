#include<iostream>
using namespace std;

bool isSortedArray(int arr[], int n)
{
    if(n==1 or n==0)
        return true;

    if(arr[0]<arr[1] and isSortedArray(arr+1, n-1))
        return true;

    return false;
}

int main()
{
    int arr[]={1,2,4,8,9,18,29};
    int n=sizeof(arr)/sizeof(int);

    cout<<isSortedArray(arr,n);

    return 0;
}
