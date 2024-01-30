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
using ld = long double;

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
        ld w; cin>>w;
        vector<pair<ld,ld>> a(n);
        for (auto &it : a)
            cin>>it.first>>it.second;
        sort(ALL(a), [](pair<ld,ld> a, pair<ld,ld> b)
        {
            return a.first / a.second > b.first / b.second;
        });
        deb(a)
        ld ans = 0;
        FOR(i,0,n-1)
        {
            if (w > a[i].second) 
            {
                ans += a[i].first;
                w -= a[i].second;
            }
            else
            {
                ans += w / a[i].second * a[i].first;
                break;
            }
        }
        cout<<fixed<<setprecision(2)<<ans<<"\n";
    }
}
