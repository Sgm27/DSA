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
int n,m,par[maxn],dfs_timer,low[maxn],id[maxn];
vi g[maxn],joint;
void dfs(int u)
{
    int Node = (par[u] != 0);
    low[u] = id[u] = ++dfs_timer;
    for (int v : g[u])
        if (par[u] != v)
        {
            if (id[v]) low[u] = min(low[u], id[v]);
            else 
            {
                par[v] = u;
                dfs(v);
                low[u] = min(low[u], low[v]);
                if (low[v] >= id[u]) Node++;
            }
        }
    if (Node >= 2) joint.push_back(u);
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
        joint.clear();
        dfs_timer = 0;
        FOR(i,1,n) 
        {
            low[i] = id[i] = par[i] = 0;
            g[i].clear();
        }	
        FOR(i,1,m)
        {
            int u,v; cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        FOR(i,1,n)
            if (!id[i]) dfs(i);
        sort(ALL(joint));
        for (int x : joint) cout<<x<<" ";
        cout<<"\n";
    }
}
