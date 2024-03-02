#include<bits/stdc++.h>
using namespace std;
int factorial(int n)
{
    //base case
    if(n==0) return 1;
    int chotoFactorial = factorial(n-1);
    return chotoFactorial * n;
}
int main()
{
    int n;
    cin>>n;
    cout<<factorial(n)<<endl;
    return 0;
}