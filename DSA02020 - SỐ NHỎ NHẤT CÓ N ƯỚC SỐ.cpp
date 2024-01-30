#include<bits/stdc++.h>
#ifdef DS
    #include "debug.h"
#else 
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
const int MOD=1e9+7,INF=1e18;
#define maxn 
vi a = {2,3,5,7,11,13,17,19,23,29,31,33};
int ans,n;
void Try(int i,int cur,int cnt)
{
    if (cnt > n) return;
    if (cnt == n) 
        ans = min(ans, cur);
    FOR(j,1,63)
    {
        if (cur * a[i] > ans) 
            break;
        cur *= a[i];
        Try(i+1,cur,cnt * (j+1));
    } 
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
        ans = INF;
        cin>>n;
        Try(0,1,1);	
        cout<<ans<<"\n";
    }
}