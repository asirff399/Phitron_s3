#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int par[N];
int group_size[N];
int level[N];
void dsu_initialize(int n)
{
    for(int i=1;i<=n;i++)
    {
        par[i]=-1;
        group_size[i]=1;
        level[i]=0;
    }
    
}
int dsu_find(int node)
{
    if(par[node]==-1) return node;
    int leader= dsu_find(par[node]);
    par[node]=leader;
    return leader; 
}
void dsu_union_by_size(int node1,int node2)
{
    int leaderA=dsu_find(node1);
    int leaderB=dsu_find(node2);
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
int main()
{
    int n,e;
    cin>>n>>e;
    dsu_initialize(n);
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        int leaderA=dsu_find(a);
        int leaderB=dsu_find(b);
        if(leaderA!=leaderB)
        {
            dsu_union_by_size(a,b);
        }
    }
    vector<int> leader;
    for(int i=1;i<=n;i++)
    {
        leader.push_back(dsu_find(i));
    }
    sort(leader.begin(),leader.end());
    leader.erase(unique(leader.begin(),leader.end()),leader.end());
    cout<<leader.size()-1<<endl;
    for(int i=0;i<leader.size()-1;i++)
    {
        cout<<leader[i]<<" "<<leader[i+1]<<endl;
    }
    
    return 0;
}