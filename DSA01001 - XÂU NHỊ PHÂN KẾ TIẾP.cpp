#include<bits/stdc++.h>
#ifdef DS
    #include "debug.h"
#else 
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
        int pos = -1;
        FOD(i,s.size()-1,0)
            if (s[i] == '0')
            {
                pos = i;
                break;
            }	    
        if (pos == -1)
        {
            string ans(s.size(),'0');
            cout<<ans<<"\n";
            continue;
        }
        deb(s[pos])
        s[pos] = '1';
        deb(s[pos])
        FOR(i,pos+1,s.size()-1) s[i] = '0';
        cout<<s<<"\n";
    }
}
