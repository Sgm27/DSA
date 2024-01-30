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
#define maxn 105
int n,mark[maxn][maxn];
char a[maxn][maxn];
pii st,ed;
void bfs()
{
    queue<pii> q;
    q.push(st);
    mark[st.first][st.second] = 0;
    while (!q.empty())
    {
        auto [x,y] = q.front();
        if (x == ed.first && y == ed.second) 
            return cout<<mark[x][y]<<"\n", void();
        q.pop();
        FOR(i,x+1,n)
            if (a[i][y] == '.' && mark[i][y] == INF)
            {
                mark[i][y] = mark[x][y] + 1;
                q.push({i,y});
            }
            else break;
        FOD(i,x-1,1)
            if (a[i][y] == '.' && mark[i][y] == INF)
            {
                mark[i][y] = mark[x][y] + 1;
                q.push({i,y});
            }
            else break;
        FOR(i,y+1,n)
            if (a[x][i] == '.' && mark[x][i] == INF)
            {
                mark[x][i] = mark[x][y] + 1;
                q.push({x,i});
            }
            else break;
        FOD(i,y-1,1)
            if (a[x][i] == '.' && mark[x][i] == INF)
            {
                mark[x][i] = mark[x][y] + 1;
                q.push({x,i});
            }
            else break;
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
        cin>>n;
        FOR(i,1,n)
            FOR(j,1,n) 
            {
                cin>>a[i][j];
                mark[i][j] = INF;
            }
        cin>>st.first>>st.second>>ed.first>>ed.second;
        st.first++, st.second++, ed.first++, ed.second++;
        bfs();
    }
}
