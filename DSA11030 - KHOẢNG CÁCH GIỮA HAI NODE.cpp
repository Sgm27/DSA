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
#define int long long
#define vi vector<int>
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 1003
#define maxbit 13
int p[maxn][maxbit+1],n,h[maxn];
vi adj[maxn];
void dfs(int u,int par)
{
    for (int v : adj[u])
        if (v != par)
        {
            h[v] = h[u] + 1;
            p[v][0] = u;
            FOR(i,1,maxbit)
                p[v][i] = p[p[v][i-1]][i-1];
            dfs(v,u);
        }
}
int get_lca(int u,int v)
{
    if (h[u] < h[v]) swap(u,v);
    int delta = h[u] - h[v];
    FOR(i,0,maxbit)
        if (delta >> i & 1) u = p[u][i];
    if (u == v) return u;
    FOD(i,maxbit,0)
        if (p[u][i] != p[v][i])
        {
            u = p[u][i];
            v = p[v][i];
        }
    return p[u][0];
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
        cin>>n;
        FOR(i,1,n) adj[i].clear(),h[i] = 0;
        FOR(i,1,n-1)
        {
            int u,v; cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        h[1] = 0;
        dfs(1,-1);
        int q; cin>>q;
        while (q--)
        {
            int u,v; cin>>u>>v;
            cout<<h[u] + h[v] - 2 * h[get_lca(u,v)]<<"\n";
        }
        deb("end-test")
    }
}
