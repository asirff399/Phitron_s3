#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
char mat[N][N];
bool vis[N][N];
vector<pair<int,int>> d={{0,1},{0,-1},{-1,0},{1,0}};
int n, m;
int si,sj,di,dj;
bool valid(int i, int j) 
{
    return i >= 0 && i < n && j >= 0 && j < m && mat[i][j] != '#' && !vis[i][j];
}
void bfs(int si, int sj, int di, int dj) 
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    map<pair<int, int>, pair<int, int>> parent;
    bool found = false; 
    while (!q.empty()) 
    {
        pair<int,int> par=q.front();
        q.pop();
        int ci =par.first;
        int cj =par.second;
        for (int i=0;i<4;i++) 
        {
            int ni = ci + d[i].first;
            int nj = cj + d[i].second;
            if (valid(ni, nj)) 
            {
                q.push({ni, nj});
                vis[ni][nj] = true;
                parent[{ni, nj}] = {ci, cj};
                if (mat[ni][nj] == 'D') 
                {
                    found = true;
                    break;
                }
            }
        }
    }
    if (found) 
    {
        int ci = di, cj = dj;
        while (mat[ci][cj] != 'R')
        {
            int pi = parent[{ci, cj}].first;
            int pj = parent[{ci, cj}].second;
            if(mat[ci][cj]!='D') mat[ci][cj] = 'X'; 
            ci = pi;
            cj = pj;
        }
    }
}
int main() 
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cin >> mat[i][j];
            if (mat[i][j] == 'R') 
            {
                si = i;
                sj = j;
            } 
            else if (mat[i][j] == 'D') 
            {
                di = i;
                dj = j;
            }
        }
    }
    memset(vis, false, sizeof(vis));
    bfs(si, sj, di, dj);
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {           
                cout << mat[i][j];            
        }
        cout << endl;
    }
    return 0;
}
