#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N=1005;
char a[N][N];
bool vis[N][N];
vector<pair<ll,ll>> d={{-1,0},{1,0},{0,-1},{0,1}};
ll n,m;
ll ans=0;
bool valid(ll i,ll j) 
{
    return (i >= 0 && i < n && j >= 0 && j < m && a[i][j] == '.' && !vis[i][j]);
}
void dfs(ll si,ll sj) 
{
    vis[si][sj]=true;
    ans++;
    for(ll i=0;i<4;i++) 
    {
        ll ci=si+d[i].first;
        ll cj=sj+d[i].second;
        if(valid(ci,cj)) 
        { 
            dfs(ci,cj);
        }
    }
}
int main() 
{
    cin >> n >> m;
    for(ll i=0;i<n;i++) 
    {
        for(ll j=0;j<m;j++) 
        {
            cin >> a[i][j];
        }
    }
    memset(vis,false,sizeof(vis));
    ll mn = LLONG_MAX;
    bool found = false;
    for(ll i=0;i<n;i++) 
    {
        for(ll j=0;j<m;j++) 
        {
            ans=0;
            if(a[i][j] == '.' && !vis[i][j]) 
            {
                dfs(i,j);
                mn=min(mn,ans);
                found = true;
            }
        }
    }
    if(found) 
        cout << mn;
    else 
        cout << -1;
    
    return 0;
}
