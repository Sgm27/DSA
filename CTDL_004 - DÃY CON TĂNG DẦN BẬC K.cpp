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
    int n,k; cin>>n>>k;
    vi a(n+1);
    FOR(i,1,n) cin>>a[i];
    vector<vi> dp(n+1,vi(k+1));
    dp[0][0] = 1;
    FOR(i,1,n)
    {
        FOR(j,0,i-1)
            if (a[i] > a[j])
                FOR(kk,1,k)
                    dp[i][kk] += dp[j][kk - 1];
    }
    int ans = 0;
    FOR(i,1,n)
        ans += dp[i][k];
    cout<<ans;
}
