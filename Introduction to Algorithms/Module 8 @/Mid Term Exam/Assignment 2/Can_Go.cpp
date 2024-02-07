#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int N = 1e3 + 5;

class Edge {
public:
    int v;
    long long w;
    Edge(int v, long long w) : v(v), w(w) {}
};

vector<vector<Edge>> graph(N);
vector<long long> dis(N, INF);

void dijkstra(int src) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, src});
    dis[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        long long cur_dis = pq.top().first;
        pq.pop();

        if (cur_dis > dis[u]) {
            continue;
        }

        for (const Edge& e : graph[u]) {
            int v = e.v;
            long long weight = e.w;

            if (dis[u] + weight < dis[v]) {
                dis[v] = dis[u] + weight;
                pq.push({dis[v], v});
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    while (e--) {
        int u, v;
        long long c;
        cin >> u >> v >> c;
        graph[u].push_back(Edge(v, c));
    }

    int src;
    cin >> src;

    int t;
    cin >> t;

    while (t--) {
        int dest;
        long long cost;
        cin >> dest >> cost;

        fill(dis.begin(), dis.end(), INF);
        dijkstra(src);

        if (dis[dest] != INF && dis[dest] <= cost) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
