#include<bits/stdc++.h>
#ifdef DS
    #include "debug.h"
#else 
    #define deb(...) 
#endif
using namespace std;
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FOD(i,a,b) for (int i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define NALL(x) x.begin()+1,x.end()
#define TIME "Time elapsed : "<<(double)clock()/1000<<" s"
#define int long long
#define bit(i,n) (n>>i&1)
#define vi vector<int>
#define pii pair<int,int>
const int MOD=1e9+7,INF=2e9;
#define maxn 

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
        int n; cin>>n;
        int a[n][n];
        FOR(i,0,n-1)
            FOR(j,0,n-1) cin>>a[i][j];
        vector<vi> dp(n,vi(1<<n,INF));
        for (int mask = 1;mask < (1<<n);mask++)
            FOR(i,0,n-1)
            {
                if (bit(i,mask) == 0) continue;
                int pre_mask = mask - (1<<i);
                if (pre_mask == 0) 
                {
                    dp[i][mask] = 0;
                    continue;
                }
                FOR(j,0,n-1)
                    if (bit(j,pre_mask))
                        dp[i][mask] = min(dp[i][mask], dp[j][pre_mask] + a[j][i]);
            }
        int ans = INF;
        FOR(i,0,n-1)
            ans = min(ans, dp[i][(1<<n) - 1]);
        cout<<ans<<"\n";	
    }
}
