#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool value(ll n)
{
    vector<bool> opt(n + 1, false);
    opt[1] = true;
    for (ll i = 1; i <= n; ++i) 
    {
        if (opt[i]) 
        {
            if (i + 3 <= n)
                opt[i + 3] = true;
            if (i * 2 <= n)
                opt[i * 2] = true;
        }
    }
    return opt[n];
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (value(n)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}



