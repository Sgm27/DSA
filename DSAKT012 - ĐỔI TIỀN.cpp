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
int n,s,ans = -1;
vi a;
void Try(int i,int cnt = 0,int cur_sum = 0)
{
    if (ans != -1 || i == n+1) return;
    if (cur_sum == s) 
    {
        ans = cnt;
        return;
    }
    if (cur_sum + a[i] <= s)
        Try(i+1, cnt+1, cur_sum + a[i]);
    Try(i+1, cnt, cur_sum);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>s;
    a.resize(n+1);
    FOR(i,1,n) cin>>a[i];
    sort(NALL(a), greater<int>());
    Try(1);
    cout<<ans;
}
