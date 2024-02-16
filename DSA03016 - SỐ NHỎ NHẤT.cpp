#ifdef DS
    #include "debug.h"
#else 
    #include<bits/stdc++.h>
    #define deb(...) 
#endif
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define NALL(x) x.begin()+1,x.end()
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define vi vector<int>
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 
void solve(int n,int s)
{
    if (n * 9 < s || s == 0) 
        return cout<<"-1\n", void();
    vi ans;
    while (s)
    {
        if (s > 9)
        {
            ans.push_back(9);
            s -= 9;
        } 
        else
        {
            ans.push_back(s);
            s = 0;
        }
    }
    if (ans.size() < n)
    {
        ans.back()--;
        while (ans.size() < n) ans.push_back(0);
        ans.pop_back();
        ans.push_back(1);
    }
    reverse(ALL(ans));
    for (int x : ans) cout<<x;
    cout<<"\n";
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        int s,n; cin>>s>>n;
        solve(n,s);	
    }
}
