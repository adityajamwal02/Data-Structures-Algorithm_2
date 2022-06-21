#include<iostream>
#include<vector>
using namespace std;

//BOTTOM-UP
int wines(int prices[], int n)
{
    vector<vector<int> > dp(n+1,vector<int>(n+1,0));

    //filling bottom to top

    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<n;j++)        //Iterative Calling and using stored values from dp array
        {
            if(i==j)
            {
                dp[i][i]=n*prices[i];
            }
            else if(i<j)
            {
                int y=n-(j-i);
                int pick_left=prices[i]*y + dp[i+1][j];
                int pick_right=prices[j]*y + dp[i][j-1];

                dp[i][j]=max(pick_left,pick_right);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return dp[0][n-1];
}

int main()
{
    int arr[]={2,3,5,1,4};
    int n=5;
    int dp[10][10]={0};
    cout<<wines(arr,n)<<endl;
    return 0;
}
