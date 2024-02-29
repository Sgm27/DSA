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
#define maxn 
const int dx[] = {-2, -2, -1, -1,  1,  1,  2,  2};
const int dy[] = {-1,  1, -2,  2, -2,  2, -1,  1};
#define N 8
int vis[N+1][N+1];
int s,t;
int bfs(int i,int j)
{
    queue<pii> q;
    q.push({i,j});
    memset(vis, 0, sizeof vis);
    vis[i][j] = 1;
    while (!q.empty())
    {
        auto [x,y] = q.front();
        q.pop();
        FOR(k,0,7)
        {
            int xx = x + dx[k];
            int yy = y + dy[k];
            if (xx >= 1 && xx <= N && yy >= 1 && yy <= N && !vis[xx][yy])
            {
                vis[xx][yy] = vis[x][y] + 1;
                q.push({xx,yy});
            }
        }
    }
    return vis[s][t] - 1;
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
        string A,B;	
        cin>>A>>B;
        int a = A[0] - 'a' + 1, b = A[1] - '0';
        s = B[0] - 'a' + 1, t = B[1] - '0';
        cout<<bfs(a,b)<<"\n";
    }
}
