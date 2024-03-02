#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5 + 5;
ll par[N];
ll group_size[N];
vector<pair<ll, pair<ll, ll>>> edges; 
ll dis[N];
class cmp 
{
public:
    bool operator()(pair<ll,ll> a, pair<ll,ll> b) 
    {
        return a.second > b.second;
    }
};
void dsu_initialize(ll n) 
{
    for (ll i = 1; i <= n; i++) 
    {
        par[i] = i;
        group_size[i] = 1;
    }
}

ll dsu_find(ll node) {
    if (par[node] == node) 
    return node;
    ll leader = dsu_find(par[node]);
    par[node]=leader;
    return leader;
}

void dsu_union_by_size(ll node1, ll node2) 
{
    ll leaderA = dsu_find(node1);
    ll leaderB = dsu_find(node2);
    if (leaderA != leaderB) 
    {
        if (group_size[leaderA] > group_size[leaderB]) 
        {
            par[leaderB] = leaderA;
            group_size[leaderA] += group_size[leaderB];
        } 
        else 
        {
            par[leaderA] = leaderB;
            group_size[leaderB] += group_size[leaderA];
        }
    }
}

int main() 
{
    ll n, m;
    cin >> n >> m;
    dsu_initialize(n);
    for (ll i = 0; i < m; i++) 
    {
        ll a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }
    sort(edges.begin(), edges.end());
    ll roads = 0;
    ll totalCost = 0;
    ll cnt=0;
    for (pair<ll,pair<ll,ll>> edge : edges) 
    {
        ll cost = edge.first;
        ll city1 = edge.second.first;
        ll city2 = edge.second.second;
        ll leaderA = dsu_find(city1);
        ll leaderB = dsu_find(city2);
        if (leaderA != leaderB) 
        {
            dsu_union_by_size(city1, city2);
            totalCost += cost;
            cnt++;
        } 
        else 
        {
            roads++;
        }
    }
    
    if(cnt==n-1)cout << roads << " " << totalCost;
    else cout << "Not Possible";
    return 0;
}
