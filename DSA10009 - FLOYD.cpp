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
int f[maxn][maxn];
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
        int n,m; cin>>n>>m;	
        FOR(i,1,n)
            FOR(j,i+1,n)
                f[i][j] = f[j][i] = INF;
        FOR(i,1,m)
        {
            int u,v,w; 
            cin>>u>>v>>w;
            f[u][v] = f[v][u] = min(f[u][v], w);
        }
        FOR(k,1,n)
            FOR(u,1,n)
                FOR(v,1,n) 
                    f[u][v] = min(f[u][v], f[u][k] + f[k][v]);
        int q; cin>>q;
        while (q--)
        {
            int u,v; cin>>u>>v;
            deb(u,v)
            cout<<f[u][v]<<"\n";
        }
    }
}
