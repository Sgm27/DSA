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
struct Fenwick{
    vector<int> t;
    int n;
    Fenwick(int sz)
    {
        n=sz;
        t.assign(n+1,0);
    }
    void update(int x,int val)
    {
        for (++x;x<=n;x+=x&-x) t[x] = max(t[x], val);
    }
    int get(int x)
    {
        int ans=0;
        for (++x;x>0;x-=x&-x) ans = max(ans, t[x]);
        return ans;
    }
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
        vector<pii> a(n+1);
        FOR(i,1,n)
            cin>>a[i].first;
        FOR(i,1,n)
            cin>>a[i].second;
        sort(NALL(a));
        Fenwick fw(1003);
        int ans = 0;
        FOR(i,1,n)
        {
            int cur = fw.get(a[i].first) + 1;
            ans = max(ans, cur);
            fw.update(a[i].second, cur);
        }	
        cout<<ans<<"\n";
    }
}