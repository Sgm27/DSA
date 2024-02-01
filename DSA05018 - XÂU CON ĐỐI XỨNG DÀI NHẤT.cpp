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
int manacher(string t)
{
    string s = ".";
    for (char c : t)
    {
        s += c;
        s += '.';
    }
    int n = s.length();
    vi d(n);
    int l = 0, r = -1;
    FOR(i,0,n-1)
    {
        int k = 0;
        if (i <= r)
            k = min(r-i, d[r-i+l]);
        while (i+k+1 < n && i-k-1 >= 0 && s[i+k+1] == s[i-k-1]) k++;
        d[i] = k;
        if (i+k > r)
            l = i-k, r = i+k;
    }
    int ans = -1;
    FOR(i,0,n-1)
        ans = max(ans, d[i]);
    return ans;
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
        string s; cin>>s;
        cout<<manacher(s)<<"\n";	
    }
}
