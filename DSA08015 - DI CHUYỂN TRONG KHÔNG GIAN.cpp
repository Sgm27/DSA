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
#define maxn 35
int dx[] = {1,0,0,-1,0,0};
int dy[] = {0,1,0,0,-1,0};
int dz[] = {0,0,1,0,0,-1};
int X,Y,Z,a[maxn][maxn][maxn];
int sx,sy,sz,ex,ey,ez;
int mark[maxn][maxn][maxn];
bool inside(int x,int y,int z)
{
    if (x >= 1 && x <= X && y >= 1 && y <= Y && z >= 1 && z <= Z) return true;
    return false;
}
void bfs(int i,int j,int k)
{
    queue<pair<pii,int>> q;
    q.push({{i,j},k});
    mark[i][j][k] = 1;
    while (!q.empty())
    {
        auto tmp = q.front();
        q.pop();
        int x = tmp.first.first;
        int y = tmp.first.second;
        int z = tmp.second;
        FOR(kk,0,5)
        {
            int xx = x + dx[kk];
            int yy = y + dy[kk];
            int zz = z + dz[kk];
            if (inside(xx,yy,zz) && a[xx][yy][zz] == 0 && !mark[xx][yy][zz])
            {
                mark[xx][yy][zz] = mark[x][y][z] + 1;
                if (xx == ex && yy == ey && zz == ez) 
                {
                    cout<<mark[x][y][z]<<"\n";
                    return;
                }
                q.push({{xx,yy},zz});
            }
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
        cin>>X>>Y>>Z;
        FOR(i,1,X)
            FOR(j,1,Y)
                FOR(k,1,Z)
                {
                    char c; cin>>c;
                    mark[i][j][k] = a[i][j][k] = 0;
                    if (c == 'S')
                        sx = i, sy = j, sz = k;
                    if (c == 'E')
                        ex = i, ey = j, ez = k;
                    if (c == '#') 
                        a[i][j][k] = 1;
                }   
        bfs(sx,sy,sz);	
    }
}
