#include <bits/stdc++.h>
using namespace std;

const long long INF = LLONG_MAX;
const int N = 1e5 + 5;

class Edge 
{
 public:
    int v;
    long long w;
    Edge(int v, long long w)
    {
        this->v=v;
        this->w=w;
    }
};

vector<vector<Edge>> graph(N);
vector<long long> dis(N, INF);

bool bellmanFord(int src, int n) 
{
    dis[src] = 0;

    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            for (auto e : graph[j]) 
            {
                int v = e.v;
                long long weight = e.w;

                if (dis[j] != INF && dis[j] + weight < dis[v]) 
                {
                    dis[v] = dis[j] + weight;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) 
    {
        for (auto e : graph[i])
        {
            int v = e.v;
            long long weight = e.w;

            if (dis[i] != INF && dis[i] + weight < dis[v]) 
            {
                return true; 
            }
        }
    }

    return false;
}

int main() 
{
    int n, e;
    cin >> n >> e;

    while (e--) 
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        graph[a].push_back(Edge(b, w));

    }

    int s;
    cin >> s;

    if (bellmanFord(s, n)) 
    {
        cout << "Negative Cycle Detected" << endl;
        return 0;
    }

    int t;
    cin >> t;

    while (t--) 
    {
        int d;
        cin >> d;

        for (int i = 0; i <= n; i++) 
        {
            dis[i] = INF;
        }


        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, s});
        dis[s] = 0;

        while (!pq.empty()) 
        {
            int u = pq.top().second;
            long long cur_dis = pq.top().first;
            
            pq.pop();

            if (cur_dis > dis[u]) 
            {
                continue;
            }

            for (auto e : graph[u]) 
            {
                int v = e.v;
                long long weight = e.w;

                if (dis[u] + weight < dis[v]) 
                {
                    dis[v] = dis[u] + weight;
                    pq.push({dis[v], v});
                }
            }
        }

        if (dis[d] != INF)  cout << dis[d] << endl;
        else  cout << "Not Possible" << endl;
        
    }

    return 0;
}