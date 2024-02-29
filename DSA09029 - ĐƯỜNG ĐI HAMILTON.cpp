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
int n,m,mark[maxn];
vi g[maxn];
bool dfs(int u,int cnt = 1)
{
    if (cnt == n) return 1;
    mark[u] = 1;
    bool res = false;
    for (int v : g[u])
        if (!mark[v]) res |= dfs(v, cnt+1);
    mark[u] = 0;
    return res;
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
        FOR(i,1,maxn-3) g[i].clear();
        FOR(i,1,m)
        {
            int u,v; cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        bool ans = false;
        FOR(i,1,n)
        {
            FOR(j,1,maxn-3) mark[j] = 0;
            if (dfs(i)) 
            {
                ans = true;
                break;
            }
        }
        cout<<ans<<"\n";
    }
}