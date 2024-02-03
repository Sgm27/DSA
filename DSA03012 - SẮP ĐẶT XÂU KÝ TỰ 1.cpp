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
        string s; cin>>s;	
        map<int,int> cnt;
        int max_cnt = 0;
        for (char c : s)
        {
            cnt[c]++;
            max_cnt = max(max_cnt, cnt[c]);
        }
        if (s.length() % 2 == 0)
        {
            if (max_cnt <= s.length() / 2) cout<<"1\n";
            else cout<<"-1\n";
        }
        else
        {
            if (max_cnt <= s.length() / 2 + 1) cout<<"1\n";
            else cout<<"-1\n";
        }
    }
}
