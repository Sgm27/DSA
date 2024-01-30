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
#define maxn 505
int n,m,a[maxn][maxn],mark[maxn][maxn];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
vector<pii> need,wait;
void bfs()
{
    queue<pii> q;
    for (auto it : wait) q.push(it);
    while (!q.empty())
    {
        auto [x,y] = q.front();
        q.pop();
        FOR(k,0,3)
        {
            int xx = x + dx[k];
            int yy = y + dy[k];
            if (xx >=1 && xx <= n && yy >= 1 && yy <= m && mark[xx][yy] == 0 && a[xx][yy] != 0)
            {
                mark[xx][yy] = mark[x][y] + 1;
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
        need.clear();
        wait.clear();
        cin>>n>>m;
        FOR(i,1,n)
            FOR(j,1,m) 
            {
                cin>>a[i][j];
                mark[i][j] = 0;
                if (a[i][j] == 2)
                {
                    mark[i][j] = 1;
                    wait.push_back({i,j});
                }
                else
                if (a[i][j] == 1) 
                    need.push_back({i,j});
            }
        bfs();
        deb(mark[3][1])
        int ans = -INF;
        for (auto [x,y] : need)
            if (mark[x][y]) ans = max(ans, mark[x][y]);
            else 
            {
                ans = 0;
                break;
            }
        cout<<(ans ? ans - 1 : -1)<<"\n";
    }
}
