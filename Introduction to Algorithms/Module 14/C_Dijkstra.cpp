#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll,ll>
const ll N=1e5+5;
vector<pi> v[N];
ll parent[N];
ll dis[N];
class cmp
{
    public:
    bool operator()(pi a,pi b)
    {
        return a.second > b.second;
    }
};
void diajkstra(ll src)
{
    priority_queue<pi,vector<pi>,cmp> pq;
    pq.push({src,0});
    dis[src]=0;
    while(!pq.empty())
    {
        pi par=pq.top();
        pq.pop();
        ll node=par.first;
        ll cost=par.second;
        for(pi child:v[node])
        {
            ll childNode=child.first;
            ll childCost=child.second;
            if(cost+childCost < dis[childNode])
            {
                dis[childNode]=cost+childCost;
                pq.push({childNode,dis[childNode]});
                parent[childNode]=node;
            }
        }
    }
}
int main()
{
    ll n,e;
    cin>>n>>e;
    while(e--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    for(ll i=0;i<N;i++)
    {
       
        dis[i]=1e18;
        parent[i]=-1;
    }
    diajkstra(1);
    if(dis[n]==1e18)
    {
        cout<<-1<<endl;
    }
    else
    {
        ll x=n;
        vector<ll> path;
        while(x!=-1)
        {
            path.push_back(x);
            x=parent[x];
        }
        reverse(path.begin(),path.end());
        for(ll v:path)
        {
            cout<<v<<" ";
            
        }cout<<endl;
    }
    
    return 0;
}
