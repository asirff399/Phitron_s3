#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin>>n>>e;
    vector<int> mat[n];
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }
    for(int x:mat[0])
    {
        cout<<x<<' ';
    }cout<<endl;
    for(int x:mat[1])
    {
        cout<<x<<' ';
    }cout<<endl;
    for(int x:mat[2])
    {
        cout<<x<<' ';
    }cout<<endl;
    for(int i=0;i<mat[3].size();i++)
    {
        cout<<mat[3][i]<<" ";
    }cout<<endl;
    for(int i=0;i<mat[4].size();i++)
    {
        cout<<mat[4][i]<<" ";
    }cout<<endl;
    for(int i=0;i<mat[5].size();i++)
    {
        cout<<mat[5][i]<<" ";
    }
    return 0;
}