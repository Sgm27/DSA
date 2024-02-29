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
        int n; cin>>n;
        vi a;
        FOR(i,1,n)
        {
            int val; cin>>val;
            if (val) a.push_back(val);
        }
        sort(ALL(a));
        string s1,s2;
        for (int i=0;i<a.size();i+=2) s1.push_back(a[i]+'0');
        for (int i=1;i<a.size();i+=2) s2.push_back(a[i]+'0');
        cout<<stoll(s1) + stoll(s2)<<"\n";
    }
}
