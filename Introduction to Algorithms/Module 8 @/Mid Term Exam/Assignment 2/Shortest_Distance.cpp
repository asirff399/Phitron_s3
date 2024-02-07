#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll INF = 1e18;
const ll N = 105; 
ll dist[N][N];
int main() 
{
    ll n, e;
    cin >> n >> e;  
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == j) 
            {
                dist[i][j] = 0;
            } else {
                dist[i][j] = INF;
            }
        }
    }   
    for (int i = 0; i < e; ++i)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        dist[a][b] = min(dist[a][b], w);
    }
    for (int k = 1; k <= n; ++k) 
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    ll q;
    cin >> q;
    for (int i = 0; i < q; ++i) 
    {
        ll x, y;
        cin >> x >> y;

        if (dist[x][y] == INF) cout << -1 << endl; 
        else cout << dist[x][y] << endl;
    }
    return 0;
}