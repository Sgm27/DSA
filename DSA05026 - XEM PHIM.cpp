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
    int tc = 1;
    while (tc--)
    {
        int n,C;
        cin>>C>>n;
        vi a(n+1);
        FOR(i,1,n) cin>>a[i];
        vi dp(C+1);
        int ans = -1;
        dp[0] = 1;
        FOR(i,1,n)
            FOD(c,C,a[i])
                if (dp[c-a[i]]) 
                {
                    dp[c] = 1;
                    ans = max(ans, c);
                }
        cout<<ans<<"\n";
    }
}
