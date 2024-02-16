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
int n,m,visited[maxn];
vi g[maxn];
vector<pii> path;
void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int nxt : g[cur])
            if (!visited[nxt])
            {
                path.push_back({cur, nxt});
                visited[nxt] = 1;
                q.push(nxt);
            }
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
        int u; 
        cin>>n>>m>>u;
        path.clear();
        FOR(i,1,n) 
        {
            g[i].clear();
            visited[i] = 0;
        }
        FOR(i,1,m)
        {
            int x,y; cin>>x>>y;
            assert(x <= n && y <= n);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        bfs(u);
        if (path.size() == n-1)
        {
            for (auto [u,v] : path)
                cout<<u<<" "<<v<<"\n";
        }
        else 
        {
            cout<<"-1\n";
        }
    }
}
