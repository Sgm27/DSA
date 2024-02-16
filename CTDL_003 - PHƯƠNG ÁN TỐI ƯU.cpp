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
#define bit(i,n) (n>>i&1)
#define vi vector<int>
#define pii pair<int,int>
const int MOD=1e9+7,INF=4e18;
#define maxn 

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #else
    if (fopen("data.in","r"))
        freopen("data.in","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n,s; cin>>n>>s;
    vi a(n), c(n);
    int ans = 0,ans_mask;
    for (int &i : c) cin>>i;
    for (int &i : a) cin>>i;
    for (int mask = 0;mask < (1<<n);mask++)
    {
        int W = 0, V = 0;
        for (int i=0;i<n;i++)
            if (bit(i,mask)) W += a[i], V += c[i];
        if (W <= s && V > ans)
        {
            ans = V;
            ans_mask = mask;
        }
    }
    cout<<ans<<"\n";
    for (int i=0;i<n;i++) cout<<bit(i,ans_mask)<<" ";
}
