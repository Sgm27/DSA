// update van de ve tieng anh =))
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
        t.resize(n+1);
    }
    void update(int x,int val)
    {
        for (++x;x<=n;x+=x&-x) t[x]+=val;
    }
    int get(int x)
    {
        int ans=0;
        for (++x;x>0;x-=x&-x) ans+=t[x];
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
    int n; cin>>n;
    vector<pii> a(n+1);
    vi compress;
    FOR(i,1,n) 
    {
        cin>>a[i].first, compress.push_back(a[i].first);
        a[i].second = a[i].first % 2;
    }
    sort(ALL(compress));
    compress.resize(unique(ALL(compress)) - compress.begin());
    FOR(i,1,n)
        a[i].first = lower_bound(ALL(compress), a[i].first) - compress.begin();
    Fenwick fw(compress.size());
    vi wait;
    int ans = 0,cnt_even = 0;
    FOR(i,1,n)
    {
        if (a[i].second)
        {
            cnt_even += wait.size();
            for (int x : wait)
                fw.update(x,1);
            wait.clear();
        }
        else
        {
            ans += cnt_even - fw.get(a[i].first);
            wait.push_back(a[i].first);
        }
    }
    cout<<ans;
}