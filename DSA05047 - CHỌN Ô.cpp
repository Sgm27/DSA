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
#define bit(i,n) (n >> i & 1)
#define vi vector<int>
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 
bool check(int mask)
{
    FOR(i,1,3)
        if (bit(i,mask) && bit(i-1,mask)) return false;
    return true;
}
bool valid(int mask,int pre_mask)
{
    FOR(i,0,4)
        if (bit(i,mask) && bit(i,pre_mask)) return false;
    return true;
}
vi good_mask;
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    for (int mask = 0;mask < (1<<4);mask++)
        if (check(mask)) good_mask.push_back(mask);
    while (tc--)
    {
        int n; cin>>n;
        vector<vi> a(4, vi(n));
        int maxx = -INF;
        FOR(i,0,3)
            FOR(j,0,n-1) cin>>a[i][j], maxx = max(maxx, a[i][j]);
        if (maxx < 0)
        {
            cout<<maxx<<"\n";
            continue;
        }
        auto get_sum = [&](int idx,int mask) -> int
        {
            int ans = 0;
            FOR(i,0,3)
                if (bit(i,mask)) ans += a[i][idx];
            return ans;
        };
        vector<vi> dp(n, vi(1<<4, 0));
        FOR(i,0,n-1)
        {
            for (int mask : good_mask)
            {
                int sum = get_sum(i,mask);
                if (i == 0) 
                {
                    dp[i][mask] = sum;
                    continue;
                }
                for (int pre_mask : good_mask)
                    if (valid(mask, pre_mask))
                       dp[i][mask] = max(dp[i][mask], dp[i-1][pre_mask] + sum);
            }
        }
        int ans = 0;
        for (int mask : good_mask)
            ans = max(ans, dp[n-1][mask]);
        cout<<ans<<"\n";
    }
}
