#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int maze[N][N];
int vis[N][N];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int n,m;
bool valid(int x,int y)
{
    return !vis[x][y]&& maze[x][y]!= -1 && x>=0 && x<n && y>=0 && y<m ;
}
void bfs(pair<int,int> src)
{
    queue<pair<int,int>> q;
    q.push(src);
    vis[src.first][src.second]=true;
    while(!q.empty())
    {
        auto par=q.front();
        int x=par.first;
        int y=par.second;
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
    cin>>n>>m;
    pair<int,int> src,dst;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<m;j++)
        {
            if(s[j] == '#')
            {
                maze[i][j]=-1;            
            }
            else
            {
                maze[i][j]= 0;
                if(s[j]=='A') src={i,j};
                if(s[j]=='B') dst={i,j}; 
            }
        }
    }
    bfs(src);
    if(vis[dst.first][dst.second])cout<<"YES";
    else cout<<"NO";
    
    return 0;
}