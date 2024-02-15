#include<bits/stdc++.h>
using namespace std;
const int N=105;
vector<int> v[N];
int dis_from_src[N];
int dis_from_dst[N];
bool vis[N];
void bfs(int src,int track)
{
    queue<int> q;
    q.push(src);
    vis[src]=true;
    if(track==1)dis_from_src[src]=0;
    else dis_from_dst[src]=0;
    while(!q.empty())
    {
        int par=q.front();
        q.pop();
        for(int child:v[par])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child]=true;
                if(track==1)dis_from_src[child]=dis_from_src[par]+1;
                else dis_from_dst[child]=dis_from_dst[par]+1;
            }
        }
    }

}
int main()
{
    int t;
    cin>>t;
    int cs=1;
    while(t--)
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
        memset(vis,false,sizeof(vis));
        memset(dis_from_src,-1,sizeof(dis_from_src));
        int s,d;
        cin>>s>>d;
        bfs(s,1);
        for(int i=0;i<n;i++)
        {
            vis[i]=false;
        }
        memset(dis_from_dst,-1,sizeof(dis_from_dst));
        bfs(d,2);
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int sum=dis_from_src[i]+dis_from_dst[i];
            ans=max(ans,sum);
        }
        cout<<"Case "<<cs++<<": "<<ans<<endl;
        for(int i=0;i<n;i++)
        {
            v[i].clear();
        }
    }
    return 0;
}