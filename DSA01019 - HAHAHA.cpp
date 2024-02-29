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
#define bit(i,n) (n>>i&1)
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
    // tc = 1;
    while (tc--)
    {
        int n,k; cin>>n;
        auto check = [&](int mask)
        {
            FOR(i,1,n-1)
                if (bit(i,mask) && bit(i-1,mask)) return 0;
            return 1;
        };
        vector<vector<char>> ans;
        for (int mask = 0;mask < (1<<n);mask++)
        {
            if (bit(0,mask) == 0 || bit(n-1,mask) == 1 || !check(mask)) continue;
            vector<char> cur;
            for (int i=0;i<n;i++)
                cur.push_back((mask >> i & 1) == 1 ? 'H' : 'A');
            ans.push_back(cur);
        }
        sort(ALL(ans));
        for (auto it : ans)
        {
            for (auto i : it) cout<<i;
            cout<<"\n";
        }
    }
}
