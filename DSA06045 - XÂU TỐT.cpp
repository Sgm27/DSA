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
    int n; cin>>n;
    vi b;
    int ans = n * (n - 1) / 2;
    string s; cin>>s;
    int cnt = 1;
    FOR(i,0,n-2)
        if (s[i] == s[i+1]) cnt++;
        else b.push_back(cnt), cnt = 1;
    b.push_back(cnt);
    for (int i=0;i<b.size()-1;i++)
        ans -= (b[i] + b[i+1] - 1);
    cout<<ans;
}