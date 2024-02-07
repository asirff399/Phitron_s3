#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
bool vis[N];
int pArray[N];
int ans;
vector<int> adj[N];
int n,e;
void dfs(int par)
{
    vis[par]=true;
    //cout<<par<<endl;
    for(int child:adj[par])
    {
        if(vis[child]==true&& child!=pArray[par])
        {
            ans=true;
        }
        if(!vis[child])
        {
            pArray[child]=par;
            dfs(child);          
        }
    }
    
}
int main()
{
    cin>>n>>e;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    memset(pArray,-1,sizeof(pArray));
    ans=false;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     cout<<pArray[i]<<" ";
    // }
    if(ans)cout<<"Cycle founded"<<endl;
    else cout<<"Cycle not founded"<<endl;
    return 0;
}