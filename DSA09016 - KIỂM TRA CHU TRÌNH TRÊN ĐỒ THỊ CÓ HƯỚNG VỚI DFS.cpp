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
bool find_cycle(int u)
{
    bool res = false;
    mark[u] = 1;
    for (int v : g[u])  
        if (mark[v] == 0) res |= find_cycle(v);
        else 
        if (mark[v] == 1) return 1;
    mark[u] = 2;
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
        FOR(i,1,n) g[i].clear(), mark[i] = 0;
        FOR(i,1,m)
        {
            int u,v; cin>>u>>v;
            g[u].push_back(v);
        }
        bool ans = false;
        FOR(i,1,n)
            if (!mark[i]) ans |= find_cycle(i);
        cout<<(ans ? "YES\n" : "NO\n");
    }
}