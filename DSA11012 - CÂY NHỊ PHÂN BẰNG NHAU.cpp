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
struct edge{
    int par, child;
    char type;
};
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
        int n; cin>>n;
        vector<edge> e1;
        FOR(i,1,n)
        {
            int par,child;
            char type;
            cin>>par>>child>>type;
            e1.push_back({par, child, type});
        }
        int m; cin>>m;
        vector<edge> e2;
        FOR(i,1,m)
        {
            int par,child;
            char type;
            cin>>par>>child>>type;
            e2.push_back({par, child, type});
        }
        sort(ALL(e1), [](edge a, edge b)
        {
            return a.par < b.par;
        });
        sort(ALL(e2), [](edge a, edge b)
        {
            return a.par < b.par;
        });
        if (e1.size() != e2.size())
        {
            cout<<"0\n";
            continue;
        }
        bool ans = true;
        FOR(i,0,e1.size()-1)
        {
            if (e1[i].par != e2[i].par) ans = false;
            if (e1[i].child != e2[i].child) ans = false;
            if (e1[i].type != e2[i].type) ans = false;
            if (!ans) break;
        }
        cout<<ans<<"\n";
    }
}
