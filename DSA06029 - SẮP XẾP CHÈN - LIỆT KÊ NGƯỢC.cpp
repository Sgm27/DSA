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
    int n; cin>>n;
    vi a(n+1);
    FOR(i,1,n) cin>>a[i];
    vector<vi> ans;
    vi cur;
    FOR(i,1,n)
    {
        auto pos = lower_bound(ALL(cur), a[i]);
        cur.insert(pos, a[i]);
        ans.push_back(cur);
    }
    for (int i=ans.size()-1;i>=0;i--)
    {
        cout<<"Buoc "<<i<<": ";
        for (int x : ans[i]) cout<<x<<" ";
        cout<<"\n";
    }
}
