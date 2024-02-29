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
        int n,key;	cin>>n>>key;
        vi a(n+1); 
        FOR(i,1,n) cin>>a[i];
        sort(NALL(a));
        deb(a)
        int ans = 0;
        FOR(i,1,n-2)
        {
            int l = i+1, r = n;
            while (l < r)
            {
                if (a[l] + a[r] + a[i] < key)
                {
                    ans += r - l;
                    l++;
                }
                else r--;
            }
        }
        cout<<ans<<"\n";
    }
}
