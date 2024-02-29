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

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n; cin>>n;
    for (int mask = 0;mask < (1<<n);mask++)
    {
        vi tmp;
        for (int i=0;i<n;i++)
            tmp.push_back(mask >> i & 1);
        vi rev = tmp;
        reverse(ALL(rev));
        if (rev == tmp)
        {
            for (int x : tmp) cout<<x<<" ";
            cout<<"\n";
        }
    }
}
