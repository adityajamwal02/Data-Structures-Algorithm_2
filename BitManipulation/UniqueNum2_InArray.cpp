#include<iostream>
using namespace std;

//Double unique number ---> BITWISE XOR

int setBit(int n, int pos)
{
    return ((n&(1<<pos))!=0);
}


int uniqueNum(int arr[], int n)
{
    int xorsum=0;
    for(int i=0;i<n;i++)
    {
        xorsum = xorsum^arr[i];
    }
    int tempxor=xorsum;
    int setbit=0;
    int pos=0;
    while(setbit!=1)
    {
        setbit=xorsum&1;
        pos++;
        xorsum=xorsum>>1;
    }

    int newxor=0;
    for(int i=0;i<n;i++)
    {
        if(setBit(arr[i],pos-1))
        {
            newxor=newxor^arr[i];
        }
    }
    cout<<newxor<<endl;
    cout<<(tempxor^newxor)<<endl;
}

int main()
{
    int arr[]={1,3,2,7,1,2};
    uniqueNum(arr,6);

    return 0;
}

