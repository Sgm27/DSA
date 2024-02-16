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

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    vi dp(100001,INF);
    dp[1] = 0;
    FOR(i,2,100000)
    {
        dp[i] = min(dp[i], dp[i-1] + 1);
        if (i % 2 == 0) dp[i] = min(dp[i], dp[i/2] + 1);
        if (i % 3 == 0) dp[i] = min(dp[i], dp[i/3] + 1);
    }
    int tc; cin>>tc;
    while (tc--)
    {
        int n; cin>>n;
        cout<<dp[n]<<"\n";
    }
}
