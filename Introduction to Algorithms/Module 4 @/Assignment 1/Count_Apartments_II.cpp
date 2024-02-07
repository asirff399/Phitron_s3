#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>> d={{0,1},{0,-1},{-1,0},{1,0}};
int n,m;
bool valid(int i,int j)
{
    if( i < 0 || i >= n || j < 0 || j >= m )
    return false;
    return true;      
}
int dfs(int si,int sj)
{

    vis[si][sj]=true;
    int rcnt= 1;
    for(int i=0;i<4;i++)
    {
        int ci=si+d[i].first;
        int cj=sj+d[i].second;
        if(valid(ci,cj)==true && !vis[ci][cj] && a[ci][cj]== '.')
        {
            rcnt+=dfs(ci,cj);
        }
    }
    return rcnt;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    memset(vis,false,sizeof(vis));
    int component=0;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j] && a[i][j]=='.')
            {
                int size= dfs(i,j);
                v.push_back(size);
                component++;
            }
        }
    }
    sort(v.begin(),v.end());
    if(v.empty())
    {
        cout<<0<<" ";
    }
    else
    {
        for(int x:v)
        {
            cout<<x<<" ";
        }
    }
    return 0;
}

