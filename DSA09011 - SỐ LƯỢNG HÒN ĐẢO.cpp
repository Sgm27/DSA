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
#define maxn 505
int n,m,a[maxn][maxn],mark[maxn][maxn];
int dx[8]={-1,0,1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,-1,1,1,-1};

void bfs(int i,int j)
{
    queue<pii> q;
    q.push({i,j});
    mark[i][j] = 1;
    while (!q.empty())
    {
        auto [x,y] = q.front();
        deb(x,y)
        q.pop();
        FOR(k,0,7)
        {
            int xx = x + dx[k];
            int yy = y + dy[k];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && !mark[xx][yy] && a[xx][yy] == 1)
            {
                mark[xx][yy] = 1;
                q.push({xx,yy});
            }
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
        cin>>n>>m;
        FOR(i,1,n)
            FOR(j,1,m)
            {
                cin>>a[i][j];
                mark[i][j] = 0;
            }
        int comp = 0;
        FOR(i,1,n)
            FOR(j,1,m)
                if (a[i][j] == 1 && !mark[i][j])
                {
                    comp++;
                    bfs(i,j);
                }
        cout<<comp<<"\n";
    }
}
