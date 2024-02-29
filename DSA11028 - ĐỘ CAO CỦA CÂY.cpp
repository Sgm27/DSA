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
#define maxn 100005
int n,mark[maxn];
vi g[maxn];
void bfs(int u)
{
    int ans = -INF;
    queue<pii> q;
    q.push({u,0});
    mark[u] = 1;
    while (!q.empty())
    {
        auto [cur, d] = q.front();
        q.pop();
        for (int nxt : g[cur])
            if (!mark[nxt]) 
            {
                mark[nxt] = 1;
                q.push({nxt, d+1});
            }
        ans = max(ans, d);
    }
    cout<<ans<<"\n";
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
        FOR(i,1,n)
        {
            g[i].clear();
            mark[i] = 0;
        }
        FOR(i,1,n-1)
        {
            int u,v; cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        bfs(1);
    }
}