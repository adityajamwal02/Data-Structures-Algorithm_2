#include<iostream>
using namespace std;

void setIthBit(int &n, int i)
{
    //small variable
    int mask = (1<<i);   // 1 left shift i
    cout<<(n|mask);

}

int main()
{
    int n=5;
    int i;
    cin>>i;

    setIthBit(n, i);
    return 0;
}

