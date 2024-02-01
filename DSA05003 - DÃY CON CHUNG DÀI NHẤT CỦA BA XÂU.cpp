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
#define maxn 102
int dp[maxn][maxn][maxn];
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
        int n,m,k; cin>>n>>m>>k;
        FOR(i,0,n)
            FOR(j,0,m)
                FOR(ii,0,k) dp[i][j][ii] = 0;
        string s1,s2,s3; cin>>s1>>s2>>s3;
        s1 = " " + s1;
        s2 = " " + s2;
        s3 = " " + s3;
        FOR(i1,1,n)
            FOR(i2,1,m)
                FOR(i3,1,k) 
                    if (s1[i1] == s2[i2] && s2[i2] == s3[i3]) 
                        dp[i1][i2][i3] = dp[i1-1][i2-1][i3-1] + 1;
                    else
                        dp[i1][i2][i3] = max({dp[i1-1][i2][i3], dp[i1][i2-1][i3], dp[i1][i2][i3-1]});
        cout<<dp[n][m][k]<<"\n";
    }
}
