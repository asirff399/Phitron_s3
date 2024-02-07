#include<bits/stdc++.h>
using namespace std;
vector<int> v[1000];
bool vis[1000];
void bfs(int scr)
{
    queue<int> q;
    q.push(scr);
    vis[scr]=true;
    while(!q.empty())
    {
        int par=q.front();
        q.pop();
        cout<<par<<endl;
        for(int i=0;i<v[par].size();i++)
        {
            int child=v[par][i];
           if(!vis[child])
           {
             q.push(child);
             vis[child]=true;
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
    bfs(scr);
    return 0;
}