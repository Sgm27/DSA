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
#define maxn 5
char a[maxn][maxn];
map<string,int> mark;
int dx[8]={-1,0,1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,-1,1,1,-1};
int n,m;
bool vis[maxn][maxn];
vector<string> ans;
void Try(int i,int j,string cur)
{
    if (mark[cur]) 
        ans.push_back(cur);
    FOR(k,0,7)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x>=1 && x<=n && y>=1 && y<=m && !vis[x][y])
        {
            vis[x][y] = 1;
            Try(x,y,cur + a[x][y]);
            vis[x][y] = 0;
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
        mark.clear();
        ans.clear();
        int k;
        cin>>k>>n>>m;
        FOR(i,1,k)
        {
            string s; cin>>s;
            if (!mark[s]) mark[s] = i;
        }
        FOR(i,1,n)
            FOR(j,1,m) cin>>a[i][j];
        FOR(i,1,n)
            FOR(j,1,m)
            {
                memset(vis, 0, sizeof vis);
                vis[i][j] = 1;
                Try(i,j,string(1,a[i][j]));
            }
        if (ans.size())
            for (auto it : ans) cout<<it<<" ";
        else cout<<-1;
        cout<<"\n";
    }
}