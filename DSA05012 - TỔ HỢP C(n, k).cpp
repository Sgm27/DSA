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
#define maxn 1003
int C[maxn][maxn];
int get(int k,int n)
{
    if (k == 1) return n;
    if (k > n) return 0;
    if (C[k][n] != -1)
        return C[k][n];
    int res = (get(k-1, n-1) + get(k, n-1)) %MOD;
    return C[k][n] = res;
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    memset(C, -1, sizeof C);
    int tc; cin>>tc;
    while (tc--)
    {
        int n,k; cin>>n>>k;
        cout<<get(k,n)<<"\n";	
    }
}
