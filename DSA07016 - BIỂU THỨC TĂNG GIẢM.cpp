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
        bool checkD = false;
        for (char c : s) 
            checkD |= (c == 'D');
        if (!checkD)
        {
            FOR(i,1,s.length()+1) cout<<i;
            cout<<"\n";
            continue;
        }
        s.push_back('I');
        int cur = 1, pre = 1;
        FOR(i,0,s.length()-1)
            if (s[i] == 'I')
            {
                if (pre != 1) cur++;
                FOD(j,cur,pre) cout<<j;
                pre = cur + 1;
            }
            else
            {
                cur++;
            }
        cout<<"\n";
    }
}
