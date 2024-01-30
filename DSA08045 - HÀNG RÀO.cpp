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
#define maxn 501
#define limit maxn*4
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
bool banned[limit+5][limit+5],cow[limit+5][limit+5],visited[limit+5][limit+5];
struct Data{
    int type,x1,y1,x2,y2;
};
vector<Data> save;
void compressX()
{
    vi comX;
    for (auto it : save)
    {
        if (it.type == 0)
        {
            comX.push_back(it.x1);
            comX.push_back(it.x2);
        }
        else
            comX.push_back(it.x1);
    }
    sort(ALL(comX));
    comX.resize(unique(ALL(comX)) - comX.begin());
    for (auto &it : save)
        if (it.type == 0)
        {
            it.x1 = lower_bound(ALL(comX), it.x1) - comX.begin() + 1;
            it.x1 = it.x1 * 2 + 1;
            it.x2 = lower_bound(ALL(comX), it.x2) - comX.begin() + 1;
            it.x2 = it.x2 * 2 + 1;
        }
        else
        {
            it.x1 = lower_bound(ALL(comX), it.x1) - comX.begin() + 1;
            it.x1 = it.x1 * 2 + 1;
        }
}
void compressY()
{
    vi comY;
    for (auto it : save)
    {
        if (it.type == 0)
        {
            comY.push_back(it.y1);
            comY.push_back(it.y2);
        }
        else
            comY.push_back(it.y1);
    }
    sort(ALL(comY));
    comY.resize(unique(ALL(comY)) - comY.begin());
    for (auto &it : save)
        if (it.type == 0)
        {
            it.y1 = lower_bound(ALL(comY), it.y1) - comY.begin() + 1;
            it.y1 = it.y1 * 2 + 1;
            it.y2 = lower_bound(ALL(comY), it.y2) - comY.begin() + 1;
            it.y2 = it.y2 * 2 + 1;
        }
        else
        {
            it.y1 = lower_bound(ALL(comY), it.y1) - comY.begin() + 1;
            it.y1 = it.y1 * 2 + 1;
        }
}
void init_map()
{
    for (auto it : save)
        if (it.type == 0)
        {
            if (it.x1 == it.x2)
                FOR(i,min(it.y1, it.y2), max(it.y1, it.y2)) banned[it.x1][i] = 1;
            else
            if (it.y1 == it.y2)
                FOR(i,min(it.x1, it.x2), max(it.x1, it.x2)) banned[i][it.y1] = 1;
        }
        else   
            cow[it.x1][it.y1] = 1;
}
void reset_map()
{
    FOR(i,1,limit)
        FOR(j,1,limit) 
            banned[i][j] = cow[i][j] = visited[i][j] = 0;
}
int bfs(int i,int j)
{
    queue<pii> q;
    q.push({i,j});
    visited[i][j] = 1;
    int ans = 1;
    while (!q.empty())
    {
        auto [x,y] = q.front();
        q.pop();
        FOR(k,0,3)
        {
            int xx = x + dx[k];
            int yy = y + dy[k];
            if (xx >= 1 && xx <= limit && yy >= 1 && yy <= limit && !banned[xx][yy] && !visited[xx][yy])
            {
                ans += cow[xx][yy];
                visited[xx][yy] = 1;
                q.push({xx,yy});
            }
        }
    }
    return ans;
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
        save.clear();
        int n,m; cin>>n>>m;
        FOR(i,1,n)
        {
            int x1,x2,y1,y2;
            cin>>x1>>y1>>x2>>y2;
            save.push_back({0,x1,y1,x2,y2});
        }
        FOR(i,1,m)
        {
            int x,y; cin>>x>>y;
            save.push_back({1,x,y,-1,-1});
        }
        compressX();
        compressY();
        init_map();
        int ans = 0;
        FOR(i,n,m+n-1)
            if (!visited[save[i].x1][save[i].y1]) 
                ans = max(ans, bfs(save[i].x1, save[i].y1));
        cout<<ans<<"\n";
        reset_map();
    }
}
