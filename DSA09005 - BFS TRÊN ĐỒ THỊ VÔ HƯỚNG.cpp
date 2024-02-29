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
vi adj[maxn], ans;
bool mark[maxn];
void bfs(int u)
{
    queue<int> q;
    q.push(u);
    mark[u] = 1;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        for (int v : adj[cur])
            if (!mark[v]) 
            {
                mark[v] = 1;
                q.push(v);
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
        int n,m,k; cin>>n>>m>>k;
        FOR(i,1,n) adj[i].clear(), mark[i] = 0;
        ans.clear();
        FOR(i,1,m)
        {
            int u,v; cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }  
        bfs(k); 
        for (int x : ans)
            cout<<x<<" ";
        cout<<"\n";	
    }
}
