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
#define maxn 200005
int n,sz[maxn],ans[maxn];
vi g[maxn];
void dfs(int u)
{
    sz[u] = 1;
    for (int v : g[u])
    {
        dfs(v);
        sz[u] += sz[v];
        ans[u] += ans[v];
    }
    ans[u] += sz[u];
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    FOR(i,2,n)
    {
        int par; cin>>par;
        g[par].push_back(i);
    }
    dfs(1);
    FOR(i,1,n) cout<<ans[i]<<" ";
}
