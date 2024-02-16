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
    int n,k; cin>>n>>k;
    vector<string> a(n+1);
    FOR(i,1,n) cin>>a[i];
    vi per;
    FOR(i,1,k) per.push_back(i);
    int res = INF;
    do{
        int mi = INF, ma = -INF;
        FOR(i1,1,n)
        {
            string cur = "";
            FOR(i2,0,k-1) cur += a[i1][per[i2] - 1];
            int num = stoll(cur);
            mi = min(mi, num);
            ma = max(ma, num);
        }
        res = min(res, ma - mi);
    }   
    while (next_permutation(ALL(per)));
    cout<<res;
}
