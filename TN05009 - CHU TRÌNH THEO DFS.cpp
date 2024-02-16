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
int n,m,trace[maxn];
bool ans;
vi g[maxn];
void dfs(int u)
{
    if (ans) return;
    for (int v : g[u])
        if (!trace[v])
        {
            trace[v] = u;
            dfs(v);
        }
        else 
        if (trace[v] == -1 && trace[u] != v)
        {
            trace[v] = u;
            ans = true;
            return;
        }
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
        ans = false;	
        FOR(i,1,n)
        {
            g[i].clear();
            trace[i] = 0;
        }
        FOR(i,1,m)
        {
            int u,v; cin>>u>>v;
            assert(u <= n && v <= n);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        FOR(i,1,n) sort(ALL(g[i]));
        trace[1] = -1;
        dfs(1);
        if (ans) 
        {
            vi path;
            path.push_back(1);
            int cur = trace[1];
            while (cur != 1) 
            {
                path.push_back(cur);
                cur = trace[cur];
            }
            path.push_back(1);
            reverse(ALL(path));
            for (int x : path)
                cout<<x<<" ";
            cout<<"\n";
        }
        else cout<<"NO\n";
    }
}
