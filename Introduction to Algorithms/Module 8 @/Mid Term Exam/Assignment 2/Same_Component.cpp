#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int mat[N][N];
int vis[N][N];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int n,e;
bool valid(int i,int j)
{
    return !vis[i][j]&& mat[i][j]!=-1&& i>=0&&i<n&&j>=0&&j<e ;
}
void bfs(pair<int,int> src)
{
   queue<pair<int,int>> q;
   q.push(src);
   vis[src.first][src.second]=true;
   while(!q.empty())
   {
     pair<int,int> par=q.front();
     int x=par.first;
     int y= par.second;
     q.pop();
     for(int i=0;i<4;i++)
     {
        int nx=x+dx[i];
        int ny=y+dy[i];
       if(valid(nx,ny))
       {
         q.push({nx,ny});
         vis[nx][ny]=true;
       }
     }
   }
}
int main()
{
    
    cin>>n>>e;
    
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<e;j++)
        {
            if(s[j]=='-')
            {
                mat[i][j]=-1;
            }
            else
            {
                mat[i][j]=0;
            }

        }
    }
    pair<int,int> src,dst;
    cin>>src.first>>src.second;
    cin>>dst.first>>dst.second;
    bfs(src);
    if(vis[dst.first][dst.second])cout<<"YES";
    else cout<<"NO";
    return 0;
}