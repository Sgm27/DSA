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
void solve(int n)
{
    vector<string> ans;
    ans.push_back("0");
    ans.push_back("1");
    FOR(i,2,n)
    {
        int cur_sz = (1 << (i-1));
        FOD(j,cur_sz-1,0) ans.push_back(ans[j]);
        FOR(j,0,cur_sz-1) ans[j] = "0" + ans[j];
        FOR(j,cur_sz,ans.size()-1) ans[j] = "1" + ans[j];
    }
    for (auto it : ans)
        cout<<it<<" ";
    cout<<"\n";
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
        int n; cin>>n;
        solve(n);	
    }
}

