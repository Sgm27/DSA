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
const int MOD=1e9+7,INF=4e18;
#define maxn 
int dp[105][50005];

int get(int i,bool gh,int sum,int k)
{
    if (sum > k) return 0;
    if (i == 0)
        return sum == k;
    if (gh == false && dp[i][sum] != -1) return dp[i][sum];
    int res = 0, maxc = 9;
    for (int c = 0;c <= maxc;c++)
    {
        bool ghm = gh & c == maxc;
        (res += get(i-1,ghm,sum + c,k)) %= MOD;
    }
    if (gh == false)
        dp[i][sum] = res;
    return res;
}
int G(int n,int k)
{
    return get(n,true,0,k);
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
        memset(dp, -1, sizeof dp);
        int n,k; cin>>n>>k;
        cout<<(G(n,k) - G(n-1,k) + MOD * MOD) %MOD<<"\n";
    }
}
