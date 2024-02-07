#include<bits/stdc++.h>
using namespace std;
vector<int> v[1000];
bool vis[1000];
int level[1000];
int parent[1000];
void bfs(int scr)
{
    queue<int> q;
    q.push(scr);
    vis[scr]=true;
    level[scr]= 0;
    while(!q.empty())
    {
        int par=q.front();
        q.pop();
       // cout<<par<<endl;
        for(int child:v[par])
        {
           if(!vis[child])
           {
             q.push(child);
             vis[child]=true;
             level[child]=level[par]+1;
             parent[child]=par;
           }
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int scr,des;
    cin>>scr>>des;
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    memset(parent,-1,sizeof(parent));
    bfs(scr);
    vector<int> path;
    int x=des;
    while(x!=-1)
    {
        path.push_back(x);
        x=parent[x];
    }
    reverse(path.begin(),path.end());
    for(int val:path)
    {
        cout<<val<<" ";
    }
    return 0;
}

