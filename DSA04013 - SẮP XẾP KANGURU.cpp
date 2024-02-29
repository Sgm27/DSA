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
    freopen("thu.out","w",stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        int n; cin>>n;	
        vi a(n+1);
        FOR(i,1,n)
            cin>>a[i];
        sort(NALL(a));
        int l1 = 1, l2 = n / 2 + 1, cnt = 0;
        while (l1 <= n / 2 && l2 <= n)
        {
            if (a[l1] * 2 <= a[l2])
            {
                l1++;
                l2++;
                cnt++;
            }
            else l2++;
        }
        cout<<n - cnt<<"\n";
    }
}
