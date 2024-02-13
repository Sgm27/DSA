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
        string s; cin>>s;	
        int n = s.length();
        vi dp(n+1);
        s = " " + s;
        dp[0] = 1;
        FOR(i,1,n)
        {
            if (i == 1) 
            {
                if (s[i] != '0') dp[i] = 1;
                continue;
            }
            if (s[i] != '0') dp[i] += dp[i-1];
            string tmp = string(1,s[i-1]) + s[i];
            if (tmp.front() != '0' && stoll(tmp) <= 26) 
                dp[i] += dp[i-2];
        }
        cout<<dp[n]<<"\n";
    }
}
