#include<bits/stdc++.h>
using namespace std;

void buildTree(int tree[],int arr[],int index,int low,int high)
{
  if(low==high)
  {
    if(arr[low]==0)
    {
      tree[index]=1;
    } else
    {
      tree[index]=0;
    }
  }
  else
  {
    int mid=(low+high)/2;
    buildTree(tree,arr,index*2,low,mid);
    buildTree(tree,arr,index*2+1,mid+1,high);
    tree[index]=tree[index*2]+tree[index*2+1];
  }
}

int find_kth(int tree[],int index,int low,int high, int k)
{
  if(tree[index]<k)
    return -1;
  if (low==high)
    return low;
  int mid =(low+high)/2;
  if(tree[index*2]>=k)
    return find_kth(tree, index * 2, low, mid, k);
  else
    return find_kth(tree, index * 2 + 1, mid + 1, high, k - tree[index * 2]);
}

int main()
{
    int k;
    int arr[]={0,1,0,1,0,0,0,0,0,1,0};
    int n=sizeof(arr)/sizeof(int);
    int tree[4*n+1];

    buildTree(tree,arr,1,0,n-1);

    cout<<" Enter K: ";
    cin>>k;
    int ans=find_kth(tree,1,0,n-1,k);
    if(ans==-1)
    cout<<endl<<"NO"<<endl;
    else
    cout<<endl<<"Index: "<<ans;
  return 0;
}
