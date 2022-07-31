/*
    Given a integer number 2022, convert into string recursively
    Input: integer number

*/


#include<iostream>
using namespace std;

string spell[]={"zero","one","two","three","four","five","six","seven","eight","nine"};

void printspell(int n)
{
    if(n==0)
        return;

    int last_digit = n%10;
    printspell(n/10);

    cout<<spell[last_digit]<<" ";
}


int main()
{
    int n;
    cin>>n;
    printspell(n);

    return 0;
}
