//BOTTOM UP APPROACH
#include<bits/stdc++.h>
using namespace std;

void bracket(int i, int j, int n, int *s, char &name)
{
    if(i==j)
    {
        cout<<name++;
        return;
    }
    cout<<"(";
    bracket(i,*((s+i*n)+j), n, s, name);

    bracket(*((s+i*n)+j)+1, j, n, s, name);
    cout<<")";
}

void mcm(int d[], int n)
{
    int m[n][n],s[n][n];
    int i,j,k;
    char name='A';

    for(i=1;i<n;i++)
        m[i][i]=0;

    for(int l=2;l<n;l++)
    {
        for(i=1;i<n-l+1;i++)
        {
            j=i+l-1;
            m[i][j]=INT_MAX;
            for(k=i;k<j;k++)
            {
                m[i][j]=min(m[i][j],m[i][k]+m[k+1][j]+(d[i-1]*d[k]*d[j]));
                s[i][j]=k;
            }
        }
    }
    cout<<"Brackets at: ";
    bracket(1,n-1,n,(int*)s,name);
    cout<<endl<<"Optimal Multiplications"<<m[1][n-1];
}

int main()
{
    int arr[]={40, 20, 30, 10, 30 };
    int n=sizeof(arr)/sizeof(int);
    mcm(arr,n);
    return 0;
}
