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
#define maxn 25
int c1[maxn],c2[maxn],n,hang[maxn],a[maxn][maxn];
int ans,cur;
void Try(int i)
{
    FOR(j,1,n)
        if (hang[j] == 0 && c1[i-j+n] == 0 && c2[i+j] == 0)
        {
            hang[j] = 1;
            c1[i-j+n] = 1;
            c2[i+j] = 1;
            cur += a[j][i];
            if (i == n)
                ans = max(ans, cur);
            else Try(i+1);
            hang[j] = 0;
            c1[i-j+n] = 0;
            c2[i+j] = 0;
            cur -= a[j][i];
        }
}
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
        ans = cur = 0;
        FOR(i,1,8)
            FOR(j,1,8) cin>>a[i][j];
        n = 8;
        FOR(i,1,maxn-1)
            hang[i] = c1[i] = c2[i] = 0;
        Try(1);
        cout<<ans<<"\n";
    }
}
