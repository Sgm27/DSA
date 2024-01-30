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
#define bit(i,n) (n >> i & 1)
#define vi vector<int>
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 1003
#define maxk 17
int n,m,k,N,cost[maxk][maxk],dp[maxk][1 << maxk];
vi tour;
vector<pii> adj[maxn];

void make_cost(int idx)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vi f(n+5, INF);
    f[tour[idx]] = 0;
    pq.push({f[tour[idx]], tour[idx]});
    while (!pq.empty())
    {
        auto [du, u] = pq.top();
        pq.pop();
        if (du != f[u]) continue;
        for (auto [v,w] : adj[u])
            if (f[v] > f[u] + w)
            {
                f[v] = f[u] + w;
                pq.push({f[v], v});
            }
    }
    for (int i=0;i<N;i++)
        if (i != idx) cost[idx][i] = f[tour[i]];
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m>>k;
    tour.push_back(1);
    FOR(i,1,k)
    {
        int x; cin>>x;
        tour.push_back(x);
    }
    FOR(i,1,m)
    {
        int u,v,w; cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    N = tour.size();
    for (int i=0;i<N;i++) make_cost(i);
    for (int32_t i=0;i<N;i++)
        for (int32_t mask=0;mask < (1 << N);mask++) dp[i][mask] = INF;
    dp[0][1] = 0;
    for (int32_t mask = 1;mask < (1 << N);mask++)
    {
        if (bit(0,mask) == 0) continue;
        for (int32_t i=1;i<N;i++)
            if (bit(i,mask))
            {
                int32_t pre_mask = mask - (1 << i);
                for (int32_t j=0;j<N;j++)
                    if (bit(j,pre_mask)) 
                        dp[i][mask] = min(dp[i][mask], dp[j][pre_mask] + cost[j][i]);
            }
    }
    int ans = INF;
    for (int i=1;i<N;i++) 
        ans = min(ans, dp[i][(1<<N) - 1] + cost[i][0]);
    cout<<(ans == INF ? -1 : ans);
}
