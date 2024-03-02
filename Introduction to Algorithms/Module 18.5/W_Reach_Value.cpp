#include<bits/stdc++.h>
using namespace std;
#define ll long long 
bool value(ll curr,ll n)
{
    if(n==curr) return true;
    if(curr > n ) return false;
    ll op1= value(curr*10,n);
    ll op2= value(curr*20,n);
    return op1 || op2;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        if(value(1,n))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}