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
#define maxn 11
string ans;
int a[maxn][maxn],n;
bool vis[maxn][maxn],has_ans;
void Try(int i,int j)
{
    if (a[i][j] == 0) return;
    if (i == n && j == n)
    {
        has_ans = true;
        cout<<ans<<" ";
        return;
    }
    if (i+1 <= n && a[i+1][j] == 1) 
    {
        ans.push_back('D');
        Try(i+1, j);
        ans.pop_back();
    }
    if (j+1 <= n && a[i][j+1] == 1)
    {
        ans.push_back('R');
        Try(i, j+1);
        ans.pop_back();
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
        has_ans = false;
        cin>>n;
        FOR(i,1,n)
            FOR(j,1,n) cin>>a[i][j];
        Try(1,1);  
        if (!has_ans) cout<<-1; 
        cout<<"\n";
    }
}
