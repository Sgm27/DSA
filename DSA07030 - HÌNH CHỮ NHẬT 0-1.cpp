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
    int tc; cin>>tc;
    while (tc--)
    {
        int n,m; cin>>n>>m;
        vector<vi> a(n+1, vi(m+1));
        FOR(i,1,n)
            FOR(j,1,m) cin>>a[i][j];
        vector<vi> sum_col(m+1, vi(n+1));
        FOR(i,1,m)
            FOR(j,1,n) sum_col[i][j] = sum_col[i][j-1] + a[j][i];
        auto getSum = [&](int col_idx, int l, int r) -> int
        {
            return sum_col[col_idx][r] - sum_col[col_idx][l-1];
        };
        int ans = 0;
        FOR(i1,1,n)
            FOR(i2,i1+1,n)
            {
                vi dp(m+1);
                FOR(i,1,m)
                {
                    if (getSum(i,i1,i2) == i2-i1+1) dp[i] = dp[i-1] + 1;
                    ans = max(ans, dp[i] * (i2-i1+1));
                }
            }
        cout<<ans<<"\n";
    }
}
