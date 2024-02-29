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
        int n,m,k; cin>>n>>m>>k;	
        vi a(n+1), b(m+1), c(k+1);
        FOR(i,1,n) cin>>a[i];
        FOR(i,1,m) cin>>b[i];
        FOR(i,1,k) cin>>c[i];
        vi ans;
        int l1 = 1, l2 = 1, l3 = 1;
        while (l1 <= n && l2 <= m && l3 <= k)
        {
            if (a[l1] == b[l2] && b[l2] == c[l3]) 
            {
                ans.push_back(a[l1]);
                l1++, l2++, l3++;
            }
            else
            {
                int mi = min({a[l1], b[l2], c[l3]});
                if (a[l1] == mi) l1++;
                if (b[l2] == mi) l2++;
                if (c[l3] == mi) l3++;
            }
        }
        if (ans.size())
            for (int x : ans) cout<<x<<" ";
        else 
            cout<<"-1";
        cout<<"\n";
    }
}
