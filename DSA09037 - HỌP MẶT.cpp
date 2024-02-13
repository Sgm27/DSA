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
int n,m,k,mark[maxn],d[maxn];
vi adj[maxn],q;
void dfs(int u)
{
    d[u] = 1;
    for (int v : adj[u])
        if (!d[v]) dfs(v);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>k>>n>>m;
    FOR(i,1,k) 
    {
        int x; cin>>x;
        q.push_back(x);
    } 
    FOR(i,1,m)
    {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
    }
    for (int x : q)
    {
        FOR(i,1,n) d[i] = 0;
        dfs(x);
        FOR(i,1,n) mark[i] += d[i];
    }
    int ans = 0;
    FOR(i,1,n) 
        if (mark[i] == k) 
        {
            deb(i)
            ans++;
        }
    cout<<ans;
}
