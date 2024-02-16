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
int n,m,mark[maxn][maxn],sx,sy,ex,ey,a[maxn][maxn];
void bfs(int i,int j)
{
    queue<pii> q;
    q.push({i,j});
    mark[i][j] = 0;
    while (!q.empty())
    {
        auto [x,y] = q.front();
        q.pop();
        if (mark[x][y] > 2) continue;
        FOR(yy,y+1,m) 
            if (mark[x][yy] == INF && a[x][yy] != 1)
            {
                mark[x][yy] = mark[x][y] + 1;
                q.push({x,yy});
            }
            else break;
        FOD(yy,y-1,1)
            if (mark[x][yy] == INF && a[x][yy] != 1)
            {
                mark[x][yy] = mark[x][y] + 1;
                q.push({x,yy});
            }
            else break;
        FOR(xx,x+1,n)
            if (mark[xx][y] == INF && a[xx][y] != 1)
            {
                mark[xx][y] = mark[x][y] + 1;
                q.push({xx,y});
            }
            else break;
        FOD(xx,x-1,1)
            if (mark[xx][y] == INF && a[xx][y] != 1)
            {
                mark[xx][y] = mark[x][y] + 1;
                q.push({xx,y});
            }
            else break;
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
                mark[i][j] = INF;
                char c; cin>>c;
                if (c == 'S') sx = i, sy = j, a[i][j] = 0;
                if (c == 'T') ex = i, ey = j, a[i][j] = 0;
                if (c == '.') a[i][j] = 0;
                if (c == '*') a[i][j] = 1;
            }        	
        bfs(sx,sy);
        // FOR(i,1,n)
        // {
        //     FOR(j,1,m) cout<<mark[i][j]<<" ";
        //     cout<<"\n";
        // }
        cout<<(mark[ex][ey] <= 3 ? "YES\n" : "NO\n");
    }
}
