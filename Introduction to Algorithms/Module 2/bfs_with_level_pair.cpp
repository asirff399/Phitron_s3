#include<bits/stdc++.h>
using namespace std;
vector<int> v[1000];
bool vis[1000];

void bfs(int scr,int des)
{
    queue<pair<int,int>> q;
    q.push({scr,0});
    vis[scr]=true;
    bool flag=false;
    while(!q.empty())
    {
        pair<int,int> p=q.front();
        q.pop();
        int par=p.first;
        int level=p.second;
        
        //cout<<par<<endl;
        if(par==des) 
        {
            cout<<level<<endl;
            flag=true;
        }
        for(int child:v[par])
        {
           if(!vis[child])
           {
             q.push({child,level+1});
             vis[child]=true;
           }
        }
    }
    if(flag==false) 
    {
        cout<<-1<<endl;
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int scr;
    cin>>scr;
    memset(vis,false,sizeof(vis));
    bfs(scr,5);
    return 0;
}
