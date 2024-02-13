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
        string a,b; cin>>a>>b;
        reverse(ALL(a));
        reverse(ALL(b));
        int r1 = 0, r2 = 0;
        FOR(i,0,a.length()-1)
            if (a[i] == '1') r1 += (1LL << i);
        FOR(i,0,b.length()-1)
            if (b[i] == '1') r2 += (1LL << i);
        cout<<(r1 * r2)<<"\n";
    }
}
