#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin>>n>>e;
    vector<int> v[n+1];
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        if(x >=0 && x<=n)
        {
            sort(v[x].begin(),v[x].end(),greater<int>());
        if(!v[x].empty())
        {
            for(int val:v[x])
            {
                cout<<val<<" ";
            }
            
        } 
        else
        {
            cout<<-1;
        }cout<<endl;
        }
        
        
    }
    return 0;
}