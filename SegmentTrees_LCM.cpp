#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int tree[4*MAX];
int arr[MAX];

int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b%a,a);
}
int lcm(int a, int b)
{ return a*b/gcd(a,b); }

void build(int node, int start, int end)
{
	if (start==end)
	{   tree[node] = arr[start]; return; }
    int mid = (start+end)/2;
	build(2*node, start, mid);
	build(2*node+1, mid+1, end);
	int left_lcm = tree[2*node];
	int right_lcm = tree[2*node+1];
	tree[node] = lcm(left_lcm, right_lcm);
}
int query(int node, int start, int end, int l, int r)
{	if (end<l || start>r)
		return 1;
	if (l<=start && r>=end)
		return tree[node];
	int mid = (start+end)/2;
	int left_lcm = query(2*node, start, mid, l, r);
	int right_lcm = query(2*node+1, mid+1, end, l, r);
	return lcm(left_lcm, right_lcm);
}
int main()
{
    for(int i=0;i<10;i++)
    { cin>>arr[i];}
	build(1, 0, 10);
	cout<<"LCM in Range(2,5) is: "<<query(1, 0, 10, 2, 5)<<endl;
	return 0;
}
