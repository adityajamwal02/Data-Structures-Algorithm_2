#include<iostream>
using namespace std;

//Single unique number ---> BITWISE XOR

int uniqueNum(int arr[], int n)
{
    int xorsum=0;
    for(int i=0;i<n;i++)
    {
        xorsum = xorsum^arr[i];
    }
    return xorsum;
}


int main()
{
    int arr[5]={1,3,2,1,2};
    cout<<uniqueNum(arr,5);

    return 0;
}
