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
#define maxn 150
int n,m,num;
int color[maxn];
vi g[maxn];
bool valid(int ver, int col)
{
    for (int x : g[ver])
        if (color[x] == col) return false;
    return true;
}
bool Try(int i)
{
    if (i == n+1) return true;
    FOR(c,1,num)
    {
        if (valid(i,c)) 
        {
            color[i] = c;
            if (Try(i+1)) return true;
            color[i] = 0;
        }
    }
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
        cin>>n>>m>>num;
        FOR(i,1,n) g[i].clear(), color[i] = 0; 
        FOR(i,1,m)
        {
            int u,v; cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        bool ans = Try(1);
        cout<<(ans ? "YES\n" : "NO\n");
    }
}
