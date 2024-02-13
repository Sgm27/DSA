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
#define maxn 101*101
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
set<int> banned[maxn];
struct DSU
{
    vector<int> r, sz;
    int n;
    DSU(int _sz)
    {
        n = _sz;
        r.resize(_sz + 1);
        sz.assign(_sz + 1, 1);
        FOR(i, 1, n)
            r[i] = i;
    }
    int get_root(int u)
    {
        if (u == r[u]) return u;
        return r[u] = get_root(r[u]);
    }
    bool join(int u, int v)
    {
        u = get_root(u);
        v = get_root(v);
        if (u == v)
            return 0;
        if (sz[u] < sz[v])
            swap(u, v);
        sz[u] += sz[v];
        sz[v] = 0;
        return r[v] = u, 1;
    }
};
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,k,m; cin>>n>>k>>m;
    auto get_idx = [&](int i,int j) -> int
    {
        return ((--i) * n) + j;
    };
    FOR(i,1,m)
    {
        int x,y,u,v; cin>>x>>y>>u>>v;
        banned[get_idx(x,y)].insert(get_idx(u,v));
        banned[get_idx(u,v)].insert(get_idx(x,y));
    }
    DSU dsu(n*n);
    FOR(i,1,n)
    {
        FOR(j,1,n)
        {
            FOR(k,0,3)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x >= 1 && y >= 1 && x <= n && y <= n && !banned[get_idx(i,j)].count(get_idx(x,y)))
                    dsu.join(get_idx(i,j), get_idx(x,y));
            }
        }
    } 
    // FOR(i,1,n)
    // {
    //     FOR(j,1,n) cout<<dsu.get_root(get_idx(i,j))<<" ";
    //     cout<<"\n";
    // }
    map<int,int> cnt;
    while (k--)
    {
        int x,y; cin>>x>>y;
        cnt[dsu.get_root(get_idx(x,y))]++;
    }
    vi num;
    int sum = 0;
    for (auto it : cnt)
    {
        sum += it.second;
        num.push_back(it.second);
    }
    deb(num)
    int ans = 0;
    for (int x : num)
        ans += x * (sum - x);
    cout<<ans / 2<<"\n";
}
