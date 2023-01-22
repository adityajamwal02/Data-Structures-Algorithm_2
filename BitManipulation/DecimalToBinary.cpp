#include<bits/stdc++.h>
using namespace std;

long long convertToBinary(long long int n){
    long long binaryNumber=0;
    long long int remainder, i=1, step=1;
    while(n!=0){
        remainder=n%2;
        n/=2;
        binaryNumber+=remainder*i;
        i*=10;
    }
    return binaryNumber;
}
int main(){
    long long int n;
    cin>>n;
    cout<<"Binary: "<<convertToBinary(n)<<endl;

    return 0;
}
