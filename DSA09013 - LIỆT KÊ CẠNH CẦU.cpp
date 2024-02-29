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
#define maxn 10005
int n,m,low[maxn],id[maxn],dfs_timer,par[maxn];
vector<pii> bridge;
vi adj[maxn];
void dfs(int u)
{
    id[u] = low[u] = ++dfs_timer;
    for (int v : adj[u])
    {
        if (v == par[u]) continue;
        if (id[v]) 
            low[u] = min(low[u], id[v]);
        else
        {
            par[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (low[v] == id[v]) 
                bridge.push_back({min(u,v), max(u,v)});
        }
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
        cin>>n>>m;	
        FOR(i,1,n) 
        {
            adj[i].clear();
            par[i] = id[i] = low[i] = 0;
        }
        dfs_timer = 0;
        bridge.clear();
        FOR(i,1,m)
        {
            int u,v; cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        FOR(i,1,n)
            if (!par[i]) dfs(i);
        sort(ALL(bridge));
        for (auto it : bridge)
            cout<<it.first<<" "<<it.second<<" ";
        cout<<"\n";
    }
}
