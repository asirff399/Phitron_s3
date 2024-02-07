#include<bits/stdc++.h>
using namespace std;
const int N=1005;
vector<int> v[N];
bool vis[N];
//int level[N];
int n,e;
void bfs(int src,int des)
{
    queue<pair<int,int>> q;
    q.push({src,0});
    vis[src]=true;
    bool flag=false;
    //level[src]=0;
    while(!q.empty())
    {
        auto p=q.front();
        q.pop();
        int par=p.first;
        int level=p.second;
        //cout<<par<<" ";
        if(par==des)
        {
            cout<<level<<endl;
            flag=true;
        }
        // for(int i=0;i<v[par].size();i++)
        // {
        //     int child=v[par][i];
        //     if(!vis[child])
        //     {
        //         q.push({child,level+1});
        //         vis[child]=true;
        //         //level[child]=level[par]+1;
        //     }
        // }
        for(int child:v[par])
        {
            if(!vis[child])
            {
                q.push({child,level+1});
                vis[child]=true;
            }
        }
    }
    if(!flag)cout<<-1<<endl;
}
int main()
{
    cin>>n>>e;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int src;
    cin>>src;
    memset(vis,false,sizeof(vis));
    //memset(level,-1,sizeof(level));
    bfs(src,9);
    // for(int i=0;i<n;i++)
    // {
    //     cout<<i<<" "<<level[i]<<endl;
    // }

    return 0;
}