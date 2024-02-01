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
        int n; cin>>n;	
        vi a(n+1);
        FOR(i,1,n) cin>>a[i];
        vi dp1(n+1), dp2(n+1);
        FOR(i,1,n)
        {
            dp1[i] = a[i];
            FOR(j,1,i-1)
                if (a[j] < a[i]) dp1[i] = max(dp1[i], dp1[j] + a[i]);
        }
        FOD(i,n,1)
        {
            dp2[i] = a[i];
            FOD(j,n,i+1)
                if (a[i] > a[j]) dp2[i] = max(dp2[i], dp2[j] + a[i]);
        }
        int ans = -1;
        FOR(i,1,n)
            ans = max(ans, dp1[i] + dp2[i] - a[i]);
        cout<<ans<<"\n";
    }
}
