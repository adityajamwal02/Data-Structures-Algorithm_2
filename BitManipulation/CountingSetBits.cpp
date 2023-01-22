
/// Count set bits (ones) in a number

#include<bits/stdc++.h>
using namespace std;

int count_bits(int n){
    int count=0;
    while(n>0){
        int last_bit=(n&1);
        count+=last_bit;

        n=n>>1;
    }
return count;
}

/*
Counting Set Bits Hack

int count_bits_hack(int n){
    int ans=0;
    while(n>0){
        n=n&(n-1);
        ans++;
    }
    return ans;
}
*/


int main(){
    int n;
    cin>>n;
    cout<<count_bits(n)<<endl;

    return 0;
}
