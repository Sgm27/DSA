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
        vector<vi> dp(n+1, vi(m+1,0));
        FOD(i,n,0)
            FOD(j,m,0) 
            {
                if (i == n && j == m)
                {
                    dp[i][j] = 1;
                    continue;
                }
                if (i < n) dp[i][j] += dp[i+1][j];
                if (j < m) dp[i][j] += dp[i][j+1];
            }   
        deb(dp)	
        cout<<dp[0][0]<<"\n";
    }
}
