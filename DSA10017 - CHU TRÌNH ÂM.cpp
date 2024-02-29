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
int n,m,f[maxn];
struct edge{
    int u,v,w;
};
vector<edge> edges;
bool bellManFord(int s)
{
    f[s] = 0;
    bool is_end;
    FOR(i,1,n)
    {
        is_end = true;
        for (auto [u,v,w] : edges)
            if (f[u] != INF && f[v] > f[u] + w)
            {
                f[v] = f[u] + w;
                is_end = false;
            }
        if (is_end) break;
    }
    deb("son")
    for (auto [u,v,w] : edges)
        if (f[u] != INF && f[v] > f[u] + w) return true;
    return false;
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
        edges.clear();
        FOR(i,1,n) f[i] = INF;
        FOR(i,1,m)
        {
            int u,v,w; cin>>u>>v>>w;
            edges.push_back({u,v,w});
        }
        bool ans = false;
        FOR(i,1,n)
            if (f[i] == INF)
            {
                if (bellManFord(i)) 
                {
                    deb(i)
                    ans = true;
                    break;
                }
            }
        cout<<ans<<"\n";
    }
}
