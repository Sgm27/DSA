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
        vi a(n+1);
        int l,r;
        FOR(i,1,n) 
            cin>>a[i];
        FOR(i,2,n)
            if (a[i] < a[i-1])
            {
                l = i-1;
                break;
            }
        FOD(i,n,1)
            if (a[i] < a[i-1])
            {
                r = i;
                break;
            }
        int mi = INF, ma = -INF;
        FOR(i,l,r)
        {
            mi = min(mi, a[i]);
            ma = max(ma, a[i]);
        }
        deb(l,r)
        int pos = -1;
        FOD(i,l-1,1)
            if (a[i] <= mi)
            {
                pos = i;
                break;
            }
        if (pos == -1) l = 1;
        else l = pos + 1;
        pos = -1;
        FOR(i,r+1,n)
            if (a[i] >= ma)
            {
                pos = i;
                break;
            }
        if (pos == -1) r = n;
        else r = pos - 1;
        deb(mi, ma)
        cout<<l<<" "<<r<<"\n";
    }
}
