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
#define vi vector<int>
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
using ld = long double;
#define maxn
struct edge{
    int u,v;
    ld dis;
    edge(int _u,int _v,ld _dis) 
    {
        u = _u;
        v = _v;
        dis = _dis;
    }
};
ld get_dis(pair<ld,ld> A,pair<ld,ld> B)
{
    return sqrt((A.first - B.first)*(A.first - B.first) + (A.second - B.second)*(A.second - B.second));
}
struct DSU{
    vector<int> r;
    int n;
    DSU(int sz)
    {
        n=sz;
        r.resize(sz+1);
        FOR(i,1,n) r[i]=i;
    }
    int get_root(int u)
    {
        if (u==r[u]) return u;
        return r[u]=get_root(r[u]);
    }
    bool join(int u,int v)
    {
        u=get_root(u);
        v=get_root(v);
        if (u==v) return 0;
        return r[u]=v, 1;
    }
};
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
        int n; cin>>n;
        vector<pair<ld,ld>> a(n+1);
        FOR(i,1,n) cin>>a[i].first>>a[i].second;
        vector<edge> edges;
        FOR(i,1,n)
            FOR(j,i+1,n)
                edges.push_back(edge(i,j,get_dis(a[i], a[j])));
        sort(ALL(edges), [](edge a,edge b)
        {
            return a.dis < b.dis;
        });
        DSU dsu(n);
        ld ans = 0;
        int cnt = 0;
        for (auto it : edges)
        {
            if (dsu.join(it.u, it.v))
            {
                ans += it.dis;
                cnt++;
            }
            if (cnt == n-1) break;
        }
        cout<<fixed<<setprecision(6)<<ans<<"\n";
    }
}
