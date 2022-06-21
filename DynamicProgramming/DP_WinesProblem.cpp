#include<iostream>
using namespace std;

// Top-Down Dp

int wines(int dp[][10], int prices[], int l, int r, int y)
{
    //BASE CASE
    if(l>r)
    {
        return 0;
    }
    //CHECKING STATE IF ALREADY COMPLETED
    if(dp[l][r]!=0)
    {
        return dp[l][r];
    }

    //RECURSIVE CASE
    int pick_left= y*prices[l] + wines(dp,prices,l+1,r,y+1);
    int pick_right= y*prices[r] + wines(dp,prices,l,r-1,y+1);

    return dp[l][r]=max(pick_left,pick_right);
}
int main()
{
    int arr[]={2,5,6,1,4,7};
    int n=6;
    int dp[10][10]={0};
    cout<<" Max Profit: "<<wines(dp,arr,0,n-1,1)<<endl<<endl;
    cout<<"\n Representation Matrix"<<endl;
    for(int i=0;i<n;i++)
    {  for(int j=0;j<n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
