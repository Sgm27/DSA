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
#define maxn 3003
int n,m,a[maxn][maxn],f[maxn][maxn];
void bfs(int i,int j)
{
    queue<pii> q;
    f[i][j] = 0;
    q.push({i,j});
    while (!q.empty())
    {
        auto [x,y] = q.front();
        deb(x,y)
        q.pop();
        int xx = x + a[x][y];
        int yy = y;
        if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && f[xx][yy] == INF) 
        {
            f[xx][yy] = f[x][y] + 1;
            if (xx == n && yy == m) 
                return cout<<f[xx][yy]<<"\n", void();
            q.push({xx,yy});
        }
        xx = x;
        yy = y + a[x][y];
        if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && f[xx][yy] == INF) 
        {
            f[xx][yy] = f[x][y] + 1;
            if (xx == n && yy == m) 
                return cout<<f[xx][yy]<<"\n", void();
            q.push({xx,yy});
        }
    }
    cout<<"-1\n";
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
        FOR(i,1,n)
            FOR(j,1,m)
            {
                cin>>a[i][j];
                f[i][j] = INF;
            }
        bfs(1,1);
    }
}
