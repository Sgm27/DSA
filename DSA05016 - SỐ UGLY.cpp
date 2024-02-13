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
vi ans;
int p2[70],p3[70],p5[70];
void init()
{
    p2[0] = p3[0] = p5[0] = 1;
    FOR(i,1,60) 
    {
        if (p2[i-1] < INF) p2[i] = p2[i-1] * 2;
        if (p3[i-1] < INF) p3[i] = p3[i-1] * 3;
        if (p5[i-1] < INF) p5[i] = p5[i-1] * 5;
    }
    FOR(i,0,60)
        FOR(j,0,60)
            FOR(k,0,60)
            {
                if (p2[i] == 0 || p3[j] == 0 || p5[k] == 0) continue;
                if (log(p2[i]) + log(p3[j]) + log(p5[k]) > log(INF)) continue;
                ans.push_back(p2[i] * p3[j] * p5[k]);
            }
    sort(ALL(ans));
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    init();
    int tc; cin>>tc;
    while (tc--)
    {
        int n; cin>>n;	
        cout<<ans[n-1]<<"\n";
    }
}
