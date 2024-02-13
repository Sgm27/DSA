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

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n; cin>>n;
    vector<vi> a(n+1, vi(n+1));
    vector<vi> adj(n+1);
    FOR(i,1,n)
        FOR(j,1,n) 
        {
            cin>>a[i][j];
            if (a[i][j]) adj[i].push_back(j);
        }
    FOR(i,1,n)
        sort(ALL(adj[i]));
    FOR(i,1,n)
    {
        for (int x : adj[i]) cout<<x<<" ";
        cout<<"\n";
    }
}
