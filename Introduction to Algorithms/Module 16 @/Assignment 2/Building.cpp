#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll N=1e5+5;
ll par[N];
ll group_size[N];
void dsu_initialize(ll n)
{
    for(ll i=0;i<n;i++)
    {
        par[i]=-1;
        group_size[i]=1;
    }
}
ll dsu_find(ll node)
{
    if(par[node]==-1)
    return node;
    ll leader=dsu_find(par[node]);
    par[node]=leader;
    return leader;
}
void dsu_union_by_size(ll node1,ll node2)
{
    ll leaderA=dsu_find(node1);
    ll leaderB=dsu_find(node2);
    if(group_size[leaderA] > group_size[leaderB])
    {
        par[leaderB]=leaderA;
        group_size[leaderA]+=group_size[leaderB];
    }
    else
    {
        par[leaderA]=leaderB;
        group_size[leaderB]+=group_size[leaderA];
    }
}
class Edge
{
    public:
    ll u,v,w;
    Edge(ll u,ll v,ll w)
    {
        this->u=u;
        this->v=v;
        this->w=w;
    }    
}; 
bool cmp(Edge a,Edge b)
{
    return a.w < b.w;
}      
int main()
{
    ll n,e;
    cin>>n>>e;
    dsu_initialize(n);
    vector<Edge> edgelist;
    while(e--)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        edgelist.push_back(Edge(u,v,w));
    }
    ll totalcost=0;
    ll cnt=0;
    sort(edgelist.begin(),edgelist.end(),cmp);
    for(Edge ed: edgelist)
    {
        ll leaderU = dsu_find(ed.u);
        ll leaderV = dsu_find(ed.v);
        if(leaderU==leaderV)
        {
            continue;
        }
        else
        {
            dsu_union_by_size(ed.u,ed.v);
            totalcost+=ed.w;
            cnt++;
        }
    }
    if(cnt==n-1)cout<<totalcost;
    else cout<<-1;
    return 0;
}