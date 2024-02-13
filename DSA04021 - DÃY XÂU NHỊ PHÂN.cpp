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
int f[93];
char get(int n,int k)
{
    if (n <= 2)
    {
        if (n == 1) return '0';
        return '1';
    }
    if (k > f[n-2]) 
        return get(n-1, k - f[n-2]);
    return get(n-2, k);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    f[0] = 0, f[1] = 1;
    FOR(i,2,92) f[i] = f[i-1] + f[i-2];
    int tc; cin>>tc;
    while (tc--)
    {
        int n,k; cin>>n>>k;
        cout<<get(n, k)<<"\n";
    }
}
