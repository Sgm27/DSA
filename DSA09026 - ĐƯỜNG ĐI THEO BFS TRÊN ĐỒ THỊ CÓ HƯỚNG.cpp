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
int n,m,s,t,trace[maxn];
vi adj[maxn];
void bfs(int u)
{
    queue<int> q;
    q.push(u);
    trace[u] = -1;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int nxt : adj[cur])
            if (!trace[nxt])    
            {
                trace[nxt] = cur;
                if (nxt == t) return;
                q.push(nxt);
            }
    }
}
void tracing(int u)
{
    vi path;
    while (trace[u] != -1)
    {
        path.push_back(u);
        u = trace[u];
    }
    path.push_back(u);
    reverse(ALL(path));
    for (int x : path) 
        cout<<x<<" ";
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
        cin>>n>>m>>s>>t;
        FOR(i,1,n)
        {
            adj[i].clear();
            trace[i] = 0;
        }
        FOR(i,1,m)
        {
            int u,v; cin>>u>>v;
            adj[u].push_back(v);
        }
        trace[s] = -1;
        bfs(s);
        if (trace[t]) tracing(t);
        else cout<<"-1\n";
    }
}
