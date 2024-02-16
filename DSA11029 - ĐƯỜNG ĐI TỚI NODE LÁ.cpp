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
#define maxn 1003
int n,par[maxn];
vi g[maxn],leaf;
void dfs(int u)
{
    if (g[u].size() == 1 && par[u] != -1) leaf.push_back(u);
    for (int v : g[u])
        if (v != par[u])
        {
            par[v] = u;
            dfs(v);
        }
}
void tracing(int u)
{
    vi path;
    while (u != -1)
    {
        path.push_back(u);
        u = par[u];
    }
    reverse(ALL(path));
    for (int x : path) cout<<x<<" ";
    cout<<"\n";
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
        leaf.clear();
        FOR(i,1,n)
        {
            par[i] = 0;
            g[i].clear();
        }
        FOR(i,1,n-1)
        {
            int u,v; cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        par[1] = -1;
        dfs(1);
        sort(ALL(leaf));
        for (int i : leaf)
            tracing(i);
    }
}
