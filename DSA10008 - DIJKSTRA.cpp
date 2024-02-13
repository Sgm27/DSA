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
int n,m,s,f[maxn];
vector<pii> adj[maxn];
void dijkstra(int s)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    FOR(i,1,n) f[i] = INF;
    f[s] = 0;
    pq.push({f[s], s});
    while (!pq.empty())
    {
        auto [fu, u] = pq.top();
        pq.pop();
        if (fu != f[u]) continue;
        for (auto [v,w] : adj[u])
            if (f[v] > f[u] + w)
            {
                f[v] = f[u] + w;
                pq.push({f[v], v});
            }
    }
    FOR(i,1,n) cout<<f[i]<<" ";
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
        cin>>n>>m>>s;
        FOR(i,1,n) adj[i].clear();
        FOR(i,1,m)
        {
            int u,v,w;
            cin>>u>>v>>w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        dijkstra(s);
    }
}
