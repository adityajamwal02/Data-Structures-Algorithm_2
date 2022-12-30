/*
Given three numbers x, y and mod, compute x raised to power y modulo mod i.e.  (x^y)%mod
Input Format
Three integers x, y and mod are passed.
Output Format
Return an integer

Sample Input
x = 12, y = 25, mod = 10007
Sample Output
9603
*/

#include <iostream>
using namespace std;


int power(int x, int y, int mod)
{
    int res=1;
    x=x%mod;
    if(x==0) return 0;
    while(y>0){
        if(y&1){
            res=(res*x)%mod;
        }
        y=y>>1;
        x=(x*x)%mod;
    }
return res;
}
