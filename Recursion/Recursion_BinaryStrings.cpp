/*
You are given an integer N. Your task is to print all binary strings of size N without consecutive ones.

Constraints:
N<=12

Input Format
In the given function an integer N is passed as parameter.

Output Format
Return a vector of strings, with all possible strings in a sorted order.


Sample Input
3

Sample Output
000
001
010
100
101
*/

#include<iostream>
#include<vector>
using namespace std;

vector<string> v;

void helper(string str, int n, int i)
{
    if(i==n)
    {
        v.push_back(str);
        return;
    }
    string s1 = str;
    s1.push_back('0');
    helper(s1,n,i+1);

    if(i>0 and str[i-1]=='0')
    {
        str.push_back('1');
        helper(str, n, i+1);
    }
    else if(i==0)
    {
        str.push_back('1');
        helper(str, n, i+1);
    }

    return;
}

vector<string> binaryStrings(int n)
{
     v.clear();
     string str;
     helper(str,n,0);

     return v;
}

int main()
{
    int n; cin>>n;
    cout<<binaryStrings(n);

    return 0;
}
