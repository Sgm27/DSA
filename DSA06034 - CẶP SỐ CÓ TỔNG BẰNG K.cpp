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
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int tc; cin>>tc;
    while (tc--)
    {
        int n,k; cin>>n>>k;
        map<int,int> mark;
        FOR(i,1,n)
        {
            int x; cin>>x;
            mark[x]++;
        }	
        int ans = 0;
        for (auto it : mark)
        {
            if (it.first > k/2) break;
            if (k%2 == 0 && it.first == k/2)
            {
                ans += it.second * (it.second - 1) / 2;
            }
            else
                ans += it.second * mark[k-it.first];
        }
        cout<<ans<<"\n";
    }
}
