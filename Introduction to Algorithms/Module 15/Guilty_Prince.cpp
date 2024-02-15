#include<bits/stdc++.h>
using namespace std;
const int N=25;
char mat[N][N];
bool vis[N][N];
int n,m;
int cnt;
vector<pair<int,int>> d={{0,1},{0,-1},{-1,0},{1,0}};
bool valid(int i,int j)
{
    return mat[i][j]=='.' && !vis[i][j] && i>=0 && i<n && j>=0 && j<m;
}
void dfs(int si,int sj)
{
    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj]=true;
    cnt++;
    while(!q.empty())
    {
        pair<int,int> par=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int ci=par.first+d[i].first;
            int cj=par.second+d[i].second;
            if(valid(ci,cj))
            {
                dfs(ci,cj);
                vis[ci][cj]=true;
                
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
        
        cin>>m>>n;
        int si,sj;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>> mat[i][j];
                if(mat[i][j]=='@')
                {
                    si=i;
                    sj=j;
                }
            }
        }
        cnt=0;
        memset(vis,false,sizeof(vis));
        dfs(si,sj);
        cout<<"Case "<<cs++<<": "<<cnt<<endl;
    }
    return 0;
}