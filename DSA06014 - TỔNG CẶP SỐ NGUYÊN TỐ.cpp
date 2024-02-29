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
const int MOD=1e9+7,INF=4e18,N=1e6;
#define maxn 
int is_prime[N+5];
vi nt;
void eratos()
{
    FOR(i,2,N) is_prime[i] = 1;
    FOR(i,2,sqrt(N))
        if (is_prime[i])
            for (int j=i*i;j<=N;j+=i) is_prime[j] = 0;
    FOR(i,2,N)
        if (is_prime[i]) nt.push_back(i);
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    eratos();
    int tc; cin>>tc;
    while (tc--)
    {
        int n; cin>>n;
        pii ans = {-1,-1};
        for (int x : nt)
        {
            if (x >= n) break;
            if (is_prime[n - x])
            {
                ans = {x,n-x};
                break;
            }
        }   	
        if (ans.first == -1)
            cout<<ans.first<<"\n";
        else
            cout<<ans.first<<" "<<ans.second<<"\n";
    }
}
