#include<bits/stdc++.h>
using namespace std;
bool get_1000(int n,int m,vector<int>& a)
{
    int target=1000-m;
    vector<vector<bool>> dp(n+1 , vector<bool>(target+1,false));
    dp[0][0]=true;
    for(int i=1;i<=target;i++) dp[0][i]=false;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=target;j++)
        {
            if(a[i-1] <=j)
            {
                dp[i][j]=dp[i-1][j-a[i-1]] || dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][target];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n,w;
    cin>>n>>w;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    if(get_1000(n,w,a)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    }
    return 0;
}

