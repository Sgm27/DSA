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
void solve(int k,string a,string b)
{
    while (a.length() < b.length()) a = "0" + a;
    while (b.length() < a.length()) b = "0" + b;
    int n = a.length(), carry = 0;
    string ans(n,' ');
    FOD(i,n-1,0)
    {
        int tmp = (a[i] - '0') + (b[i] - '0') + carry;
        if (tmp >= k) carry = 1;
        else carry = 0;
        tmp %= k;
        ans[i] = tmp + '0';
    }
    if (carry) ans.insert(ans.begin(),'1');
    cout<<ans<<"\n";
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
        int k;
        string a,b; 
        cin>>k>>a>>b;	
        solve(k,a,b);
    }
}