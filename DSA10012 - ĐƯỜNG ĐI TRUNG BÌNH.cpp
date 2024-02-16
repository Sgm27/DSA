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
        vector<vi> f(n+1,vi(n+1, INF));
        FOR(i,1,m)
        {
            int u,v; cin>>u>>v;
            f[u][v] = 1;
        }
        FOR(k,1,n)
            FOR(u,1,n)
                FOR(v,1,n) 
                    f[u][v] = min(f[u][v], f[u][k] + f[k][v]);
        int sum = 0, edge = 0;
        FOR(i,1,n)
            FOR(j,i+1,n)
                if (f[i][j] != INF) 
                {
                    sum += f[i][j] +f[j][i];
                    edge += 2;
                }
        long double ans = 1.0 * sum / edge;
        cout<<fixed<<setprecision(2)<<ans<<"\n";
    }
}
