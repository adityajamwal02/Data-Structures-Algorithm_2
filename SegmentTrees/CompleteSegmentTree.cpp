/// Segment Tree : Complete

#include<bits/stdc++.h>
using namespace std;

vector<int> nums, segmentTree, lazy;

/// Build Function: Covering index, low, high from nums array limits

void build(int i, int low, int high){
    if(low==right){
        segmentTree[i]=nums[low];
        return;
    }
    int mid=(low+high)/2;
    /// Left recursive side
    build(2*i+1,low,mid);
    /// Right recursive side
    build(2*i+2,mid+1,high);
    /// Merge Operation (Based on query, max, min, addition, subtraction, AND, OR, XOR)
    segmentTree[i]=(segmentTree[2*i+1]+segmentTree[2*i+2]);
}

/// Query Function : Covering index, low, high from nums array and left, right from current query detail

int query(int i, int low, int high, int left, int right){
    /// 3 Conditions:   Overlap, Outside-segment, Inside-segment
    if(low>=left and high<=right){
        return segmentTree[i];
    }
    if(high<left or low>right){
        return 0;                                 /// Returning sum in query, so including 0
    }
    int mid=(low+high)/2;
    int leftSide=query(2*i+1,low,mid,left,right);       /// Left Side Query
    int rightSide=query(2*i+2,mid+1,high,left,right);   /// Right Side Query

return leftSide+rightSide);                         /// Merge operation of the leftSide and rightSide
}

/// Point Update

void pointUpdate(int i, int low, int high, int node, int val){
    /// node-> to update, into val value
    if(low==high) segmentTree[i]+=val;
    else{
        int mid=(low+high)/2;
        if(node>=low and node<=mid) pointUpdate(2*i+1,low,mid,node,val);
        else pointUpdate(2*i+2,mid+1,high,node,val);
    segmentTree[i]=segmentTree[2*i+1]+segmentTree[2*i+2];
    }
}

/// Range Update (Lazy Propagation)

void rangeUpdate(int i, int low, int high, int left, int right, int val){
    /// left to right -> range update value
    if(lazy[i]!=0){
        segmentTree[i]+=(high-low+1)*lazy[i];
        if(low!=high){
            lazy[2*i+1]+=lazy[i];
            lazy[2*i+2]+=lazy[i];
        }
        lazy[i]=0;
    }
    if(right<low or left>high or low>high) return;
    if(low>=left and high<=right){
        segmentTree[i]+=(high-low+1)*val;
        if(low!=high){
            lazy[2*i+1]+=val;
            lazy[2*i+2]+=val;
        }
    return;
    }
    int mid=(low+high)/2;
    rangeUpdate(2*i+1,low,mid,left,right,val);
    rangeUpdate(2*i+2,mid+1,high,left,right,val);
segmentTree[i]=segmentTree[2*i+1]+segmentTree[2*i+2];
}

int querySumLazy(int i, int low, int high, int left, int right, int val){
    if(lazy[i]!=0){
        segmentTree[i]+=(high-low+1)*lazy[i];
        if(low!=high){
            lazy[2*i+1]+=lazy[i];
            lazy[2*i+2]+=lazy[i];
        }
        lazy[i]=0;
    }
    if(right<low or left>high or low>high) return 0;

    if(low>=left and high<=right) return segmentTree[i];

    int mid=(low+high)/2;

return querySumLazy(2*i+1,low,mid,left,right,val) + querySumLazy(2*i+2,mid+1,high,left,right,val);
}

int main(){
    int n,q;
    cin>>n>>q;
    segmentTree.resize(4*n);
    lazy.resize(4*n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    build(0,0,n-1); /// index, low, high
    while(q--){
        int left, right;
        cin>>left>>right;
        cout<<query(0,0,n-1,left,right);                /// Call To query function with query left, right parameters
    }
return 0;
}
