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
int n,m,visited[maxn],cnt;
vi g[maxn];
void dfs(int u)
{
    cnt++;
    visited[u] = 1;
    for (int v : g[u])
        if (!visited[v]) dfs(v);
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
        FOR(i,1,n) g[i].clear();
        FOR(i,1,m)
        {
            int u,v; cin>>u>>v;
            g[u].push_back(v);
        }
        deb(g[2])
        int N = 0;
        FOR(i,1,n)
        {
            FOR(j,1,n) visited[j] = 0;
            cnt = 0;
            deb(visited[4])
            dfs(i);
            deb(i, cnt)
            N += (cnt == n);
        }
        cout<<(N == n ? "YES\n" : "NO\n");
    }
}
