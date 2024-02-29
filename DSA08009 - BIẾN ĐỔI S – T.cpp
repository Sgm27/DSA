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
        int s,t;	
        cin>>s>>t;
        if (s >= t) 
        {
            cout<<s-t<<"\n";
            continue;
        }
        vi dp(t+1, INF);
        FOR(i,1,s) dp[i] = s - i;
        FOR(i,s+1,t)
            if (i & 1)
                dp[i] = dp[(i+1)/2] + 2;
            else 
                dp[i] = dp[i/2] + 1;
        deb(dp)
        cout<<dp[t]<<"\n";  
    }
}
