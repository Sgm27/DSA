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
        vector<pii> a(n+1);
        FOR(i,1,n) cin>>a[i].first>>a[i].second;
        sort(NALL(a), [](pii a, pii b)
        {
            if (a.second != b.second)
                return a.second < b.second;
            return a.first < b.first;
        });
        int cur_pos = 1, ans = 0;
        FOR(i,1,n)
            if (a[i].first >= a[cur_pos].second)
            {
                deb(i, cur_pos)
                cur_pos = i;
                ans++;
            }
        cout<<ans+1<<"\n";
    }
}
