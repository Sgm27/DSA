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
void solve(int n)
{
    int cnt7 = n / 7;
    while ((n - cnt7 * 7) % 4) 
    {
        cnt7--;
        if (cnt7 == -1) break;
    }
    if (cnt7 == -1) 
        return cout<<"-1\n", void();
    cout<<string((n - cnt7 * 7) / 4, '4') + string(cnt7, '7')<<"\n";
}
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
        solve(n);
    }
}
