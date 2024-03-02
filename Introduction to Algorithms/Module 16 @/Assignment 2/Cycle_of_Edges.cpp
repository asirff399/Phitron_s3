#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
bool vis[N];
int pArray[N];
bool ans;
int cycle=0;
vector<int> adj[N];
int n,e;
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    vis[s]=true;
    while(!q.empty())
    {
        int par=q.front();
        q.pop();
        for(int child:adj[par])
        {
            if(vis[child]&& pArray[par]!=child)
            {
                cycle++;
            }
            if(!vis[child])
            {
                pArray[child]=par;
                vis[child]=true;
                q.push(child);
            }
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
            bfs(i);
        }
    }
    cout<<cycle/2;
    return 0;
}