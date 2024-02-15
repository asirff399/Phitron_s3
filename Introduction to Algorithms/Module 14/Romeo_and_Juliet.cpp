#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5; 
vector<vector<int>> graph(N);
bool vis[N];
int dis[N];
void bfs(int node)
{
    queue<int> q;
    q.push(node);
    vis[node]=true;
    dis[node]=0;
    while (!q.empty())
    {
        int par=q.front();
        q.pop();
        for(int x: graph[par])
        {
            if(!vis[x])
            {
                vis[x]=true;
                q.push(x);
                dis[x]=dis[par]+1;
            }
        }
    }   
}
int main()
{
    int n,e;
    cin>>n>>e;
    while (e--)
    {
      int a,b;
      cin>>a>>b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    memset(dis,-1,sizeof(dis));
    int romeo,juliet,step;
    cin>>romeo>>juliet>>step;
    bfs(romeo);
    if(vis[juliet] && dis[juliet]<=step*2) cout<<"YES";
    else cout<<"NO";
    return 0;
}