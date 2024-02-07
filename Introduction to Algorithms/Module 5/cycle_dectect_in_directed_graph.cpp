#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
bool vis[N];
bool pathvis[N];
int ans;
vector<int> adj[N];
int n,e;
void dfs(int par)
{
    vis[par]=true;
    pathvis[par]=true;
    //cout<<par<<endl;
    for(int child:adj[par])
    {
        if(pathvis[child])
        {
            ans=true;
        }
        if(!vis[child])
        {
            dfs(child);
        }
    } 
    pathvis[par]=false;
}
int main()
{
    cin>>n>>e;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        //adj[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    memset(pathvis,false,sizeof(pathvis));
    ans=false;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
    if(ans)cout<<"Cycle dectected";
    else cout<<"Cycle not dectected";
    return 0;
}