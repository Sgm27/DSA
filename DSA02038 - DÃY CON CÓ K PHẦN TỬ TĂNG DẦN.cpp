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
#define bit(i,n) (n >> i & 1)
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
        int n,k; cin>>n>>k;	
        vi a(n+1);
        FOR(i,1,n)
            cin>>a[i];
        sort(NALL(a));
        vector<vi> ans;
        for (int mask=1;mask < (1 << n);mask++)
        {
            if (__builtin_popcount(mask) != k) continue;
            vi cur;
            FOR(i,1,n)
                if (bit(i-1,mask)) cur.push_back(a[i]);
            ans.push_back(cur); 
        }
        sort(ALL(ans));
        for (auto it : ans)
        {
            for (auto it2 : it) cout<<it2<<" ";
            cout<<"\n";
        }
    }
}
