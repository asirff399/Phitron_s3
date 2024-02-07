#include<bits/stdc++.h>
using namespace std;
vector<int> v[1000];
bool vis[1000];
int level[1000];
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
        cout<<par<<endl;
        for(int child:v[par])
        {
           if(!vis[child])
           {
             q.push(child);
             vis[child]=true;
             level[child]=level[par]+1;
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
    int scr;
    cin>>scr;
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    bfs(scr);
    for(int i=0;i<n;i++)
    {
        cout<<i<<" "<<level[i]<<endl;
    }
    return 0;
}
