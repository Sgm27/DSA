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
// #define int long long
#define bit(i,n) (n>>i&1)
#define vi vector<int>
#define pii pair<int,int>
const int MOD=1e9+7,INF=2e9;
#define maxn 15
int n,a[maxn][maxn],dp[maxn][1 << maxn];
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,0,n-1)
        FOR(j,0,n-1) cin>>a[i][j];
    for (int i = 0; i<n ; i++)
        for (int mask = 0;mask < (1<<n); mask++) dp[i][mask] = INF;
    dp[0][1] = 0;
    for (int mask = 1;mask < (1<<n); mask++)
    {
        if (bit(0,mask) == 0) continue;
        for (int i=1;i<n;i++)
            if (bit(i,mask))
            {
                int pre_mask = mask - (1<<i);
                for (int j=0;j<n;j++)
                    if (bit(j,pre_mask)) 
                        dp[i][mask] = min(dp[i][mask], dp[j][pre_mask] + a[j][i]);
            } 
    }
    int ans = INF;
    for (int i=0;i<n;i++)
        ans = min(ans, dp[i][(1<<n) - 1] + a[i][0]);
    cout<<ans;
}
