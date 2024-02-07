#include<bits/stdc++.h>
using namespace std;
const int N=100;
int vis[N][N];
int dx[8]={-1,1,-1,1,-2,-2,2,2};
int dy[8]={2,2,-2,-2,-1,1,-1,1};
int n,m;
bool valid(int i,int j)
{
    return i>=0&&i<n&&j>=0&&j<m ;
}
int bfs(pair<int,int> src,pair<int,int> dst)
{
   queue<pair<int,int>> q;
   q.push(src);
   vis[src.first][src.second]=1;
   while(!q.empty())
   {
     pair<int,int> par=q.front();
     int x=par.first;
     int y= par.second;
     q.pop();
     if (x == dst.first && y == dst.second) 
     {
         return vis[x][y]-1;
     }
     for(int i=0;i<8;i++)
     {
        int nx=x+dx[i];
        int ny=y+dy[i];
       if(valid(nx,ny))
       {
         q.push({nx,ny});
         vis[nx][ny]=vis[x][y]+1;  
       }
     }
   }
   return -1;
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>m;

        pair<int,int> src,dst;
        cin>>src.first>>src.second;
        cin>>dst.first>>dst.second;
        memset(vis,0,sizeof(vis));
        int ans=bfs(src,dst);
        cout<<ans<<endl;
    }
    return 0;
}