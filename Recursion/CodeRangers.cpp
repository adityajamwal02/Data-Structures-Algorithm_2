/// CodeRangers : Coding Question

#include<bits/stdc++.h>
using namespace std;

void generateCombinations(int n, int b, int c, int a, string result, int &counter){
    if(result.size()==n){
        cout<<result<<endl;
        counter++;
    return;
    }
    if(b>0) generateCombinations(n,b-1,c,a,result+"B",counter);
    if(c>0) generateCombinations(n,b,c-1,a,result+"C",counter);
    if(a>0) generateCombinations(n,b,c,a-1,result+"A",counter);
}

int main(){
    int n, b, c, a;
    cin>>n>>b>>c>>a;
    int counter=0;
    string result="";
    generateCombinations(n,b,c,a,result,counter);
    if(counter==0) cout<<"No Valid Combinations"<<endl;

    return 0;
}
