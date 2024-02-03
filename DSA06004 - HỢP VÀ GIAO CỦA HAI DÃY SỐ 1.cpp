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
        set<int> s1,s2;
        FOR(i,1,n) cin>>a[i], s1.insert(a[i]);
        FOR(i,1,m) 
        {
            cin>>b[i];
            if (s1.count(b[i])) s2.insert(b[i]);
        }
        FOR(i,1,m) s1.insert(b[i]);
        for (int i : s1) cout<<i<<" ";
        cout<<"\n";
        for (int i : s2) cout<<i<<" ";
        cout<<"\n";
    }   
}
