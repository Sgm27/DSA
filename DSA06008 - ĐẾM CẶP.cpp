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
        int n,m; cin>>n>>m;	
        vi a(n+1), b(m+1);
        FOR(i,1,n) cin>>a[i];
        int cnt_one = 0, cnt_two = 0, cnt_four = 0, cnt_zero = 0;
        FOR(i,1,m) 
        {
            cin>>b[i];
            cnt_zero += (b[i] == 0);
            cnt_one += (b[i] == 1);
            cnt_two += (b[i] == 2);
            cnt_four += (b[i] == 4);
        }
        sort(NALL(a));
        sort(NALL(b));
        int ans = 0;
        FOR(i,1,n)
        {
            if (a[i] == 0) continue;
            if (a[i] == 1)
            {
                ans += cnt_zero;
                continue;
            }
            ans += cnt_one + cnt_zero;
            if (a[i] == 3)
                ans += cnt_two;
            if (a[i] == 2)
            {
                auto pos = upper_bound(NALL(b), 3);
                ans += b.end() - pos;
                ans -= cnt_four;
            }
            else
            {
                auto pos = upper_bound(NALL(b), a[i]);
                ans += b.end() - pos;
            }
            deb(a[i], ans)
        }
        cout<<ans<<"\n";
    }
}
