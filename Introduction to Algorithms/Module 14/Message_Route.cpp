#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5; 
vector<vector<int>> graph(N);
bool vis[N];
int dis[N];
int parent[N];
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
                parent[x]=par;
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
    memset(parent,-1,sizeof(parent));
    bfs(1);
    if(dis[n]==-1)cout<<"IMPOSSIBLE"<<endl;
    else
    {
        int x=n;
        vector<int> path;
        while(x!=-1)
        {
            path.push_back(x);
            x=parent[x];
        }
        reverse(path.begin(),path.end());
        cout<<path.size()<<endl;
        for(int v:path)
        {
            cout<<v<<" ";
            
        }cout<<endl;
    }
    return 0;
}