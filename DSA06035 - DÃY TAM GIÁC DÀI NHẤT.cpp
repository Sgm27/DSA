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
        vi a(n+1), dp1(n+1), dp2(n+1);	
        FOR(i,1,n) cin>>a[i];
        FOR(i,1,n)
        {
            if (i == 1) dp1[i] = 1;
            else
            {
                if (a[i] > a[i-1]) dp1[i] = dp1[i-1] + 1;
                else 
                dp1[i] = 1;
            }
        }
        FOD(i,n,1)
        {
            if (i == n) dp2[i] = 1;
            else 
            {
                if (a[i] > a[i+1]) dp2[i] = dp2[i+1] + 1;
                else 
                dp2[i] = 1;
            }
        }
        int ans = 0;
        FOR(i,1,n)
            ans = max(ans, dp1[i] + dp2[i] - 1);
        cout<<ans<<"\n";
    }  
}
