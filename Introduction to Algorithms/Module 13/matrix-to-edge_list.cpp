#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int mat[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
           cin>>mat[i][j]; 
        }
    }
    vector<pair<int,int>> edgelist;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
           if(mat[i][j]==1&& i!=j)
           {
             edgelist.push_back({i,j});
           }
        }
    }
    for(pair<int,int> child: edgelist)
    {
        cout<<child.first<<" "<<child.second<<endl;
    }
    return 0;
}