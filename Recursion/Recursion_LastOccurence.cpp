#include<iostream>
using namespace std;

int lastOccurence(int arr[], int n, int key)
{
    //base case
    if(n==0)
        return -1;

    int subIndex = lastOccurence(arr+1, n-1, key);

    if(subIndex==-1)
    {
        if(arr[0]==key)
        { return 0;}
        else{
            return -1;
        }
    }

    return subIndex+1;
}

int main()
{
    int arr[]={1,2,3,4,5,7,9,10,6,12,19,18,6};
    int n=sizeof(arr)/sizeof(int);
    int target=6;

    cout<<lastOccurence(arr,n,target);


    return 0;
}
