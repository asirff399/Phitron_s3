#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+5;
vector<int> v[N];
bool vis[N];
void dfs(int scr)
{
   cout<<scr<<" ";
   vis[scr]=true;
   for(int child:v[scr])
   {
      if(!vis[child])
      {
        dfs(child);
      }    
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
    memset(vis,false,sizeof(vis));
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
            cout<<endl;
            c++;
        }
    }cout<<"component:-"<<c<<endl;
    

    return 0;
}