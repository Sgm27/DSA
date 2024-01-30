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
    int tc; cin>>tc;
    while (tc--)
    {
        int n; cin>>n;
        vector<int> a(n+1);
        map<int,int> mark;
        FOR(i,1,n)
        {
            cin>>a[i];
            if (!mark[a[i]]) mark[a[i]] = i;
            else mark[a[i]] = min(mark[a[i]], i);
        }
        vector<pii> b(ALL(mark));
        int min_pf = INF, ans = -INF;
        for (auto it : b)
        {
            if (min_pf == INF)
            {
                min_pf = it.second;
                continue;
            }
            ans = max(ans, it.second - min_pf);
            min_pf = min(min_pf, it.second);
        }
        cout<<ans<<"\n";
    }
}
