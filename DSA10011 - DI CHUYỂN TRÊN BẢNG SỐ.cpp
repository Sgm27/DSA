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
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int f[maxn][maxn],n,m,a[maxn][maxn];
struct Data{
    int x,y,val;
    friend bool operator<(const Data a,const Data b)
    {
        return a.val > b.val;
    }
};
void dijkstra(int i,int j)
{
    priority_queue<Data> pq;
    f[i][j] = a[i][j];
    pq.push({i,j,a[i][j]});
    while (!pq.empty())
    {
        auto [x,y,val] = pq.top();
        pq.pop();
        if (val != f[x][y]) continue;
        FOR(k,0,3)
        {
            int xx = x + dx[k];
            int yy = y + dy[k];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && f[xx][yy] > val + a[xx][yy])
            {
                f[xx][yy] = val + a[xx][yy];
                pq.push({xx,yy,f[xx][yy]});
            }
        }
    }
    cout<<f[n][m]<<"\n";
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
        dijkstra(1,1);
    }
}
