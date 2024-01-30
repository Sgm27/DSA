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
#define bit(i,n) (n >> i & 1)
#define vi vector<int>
#define pii pair<int,int>
const int MOD=1e9+7;
#define maxn 20
int n,a[maxn][maxn],dp[maxn][1 << maxn];
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
        cin>>n;
        for (int i=0;i<n;i++) 
            for (int j=0;j<n;j++) cin>>a[i][j];
        for (int i=0;i<n;i++)
            for (int j=0;j<(1<<n);j++) dp[i][j] = 0;
        for (int i=0;i<n;i++)
            for (int mask = 1;mask < (1<<n);mask++)
                if (__builtin_popcount(mask) == i+1)
                {
                    for (int j=0;j<n;j++)
                        if (bit(j,mask))
                        {
                            int pre_mask = mask - (1<<j);
                            if (pre_mask == 0) dp[i][mask] = a[j][i];
                            else
                                dp[i][mask] = max(dp[i][mask], dp[i-1][pre_mask] + a[j][i]);
                        }
                }
        cout<<dp[n-1][(1<<n) - 1]<<"\n";
    }
}
