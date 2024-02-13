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
int n,k,x[25];
vector<string> ans;
void update()
{
    vi pf(n+1);
    FOR(i,1,n)
        pf[i] = pf[i-1] + x[i];
    int cnt = 0;
    FOR(i,k,n)
        if (pf[i] - pf[i-k] == 0) cnt++;
    if (cnt == 1)
    {
        string s;
        FOR(i,1,n)
            if (x[i]) s.push_back('B');
            else s.push_back('A');
        ans.push_back(s);
    } 
}
void Try(int i)
{
    FOR(j,0,1)
    {
        x[i] = j;
        if (i == n) update();
        else Try(i+1);
    }
}
signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("thu.inp","r",stdin);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>k;
    Try(1);
    sort(ALL(ans));
    cout<<ans.size()<<"\n";
    for (auto it : ans) cout<<it<<"\n";
}
