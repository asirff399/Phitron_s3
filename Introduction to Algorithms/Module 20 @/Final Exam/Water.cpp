#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        vector<int> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            v[i]=a[i];
        }
        int mx1=0;
        int mx2=-1;
        for(int i=1;i<n;i++)
        {
            if(a[i] > a[mx1])
            {
                mx2=mx1;
                mx1=i;
            }
            else if(mx2==-1 || a[i] > a[mx2])
            {
                mx2=i;
            }
        }
        if(mx1 > mx2) swap(mx1,mx2);
        cout<<mx1<<" "<<mx2<<endl;
    }
    return 0;
}


