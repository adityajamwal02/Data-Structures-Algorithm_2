#include<iostream>
using namespace std;

int getIthBit(int n, int i)
{
    //small variable
    int mask = (1<<i);   // 1 left shift i

    return (n&mask) >0 ? 1 : 0; //if this returns greater than 0, hence it was 1 else 0
}

int main()
{
    int n=5;
    int i;
    cin>>i;
    cout<<i<<"th bit was: "<<getIthBit(n, i)<<endl;

    return 0;
}
